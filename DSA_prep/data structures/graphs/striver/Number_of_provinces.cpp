//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/*
using dfs
*/



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-->SC--> O(N)+O(N)   (visited array + recursion stack space)
//-->TC--> O(N)+O(V+2E)  (for loop n times and as a whole partial partial dfs summes up to total dfs time complexity)
//can be O(N)+O(N) if all present singly so overall       O(N)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(int node,vector<bool> &vis,vector<vector<int>> &adjlist)
  {
      vis[node]=1;
      for(auto &i:adjlist[node])
      {
          if(!vis[i])
          {
              vis[i]=1;
          dfs(i,vis,adjlist);
          }
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<vector<int>> adjlist(V);
        for(int i=0;i<V;++i)
        {
            for(int j=0;j<V;++j)
            {
                if(adj[i][j]==1 && i!=j)
                {
                adjlist[i].push_back(j);
             //   adjlist[j].push_back(i);
             //no need to give this line 
                }
            }
        }
        // for(auto &i:adjlist)
        // {
        //     for(auto &j:i)
        //     cout<<j<<" ";
        //     cout<<endl;
        // }
        int ct=0;
        vector<bool> vis(V,0);
        for(int i=0;i<V;++i)
        {
            if(!vis[i])
            {
                ct++;
                dfs(i,vis,adjlist);
            }
        }
        return ct;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends






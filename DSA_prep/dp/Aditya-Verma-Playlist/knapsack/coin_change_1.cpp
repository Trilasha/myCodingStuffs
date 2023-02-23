//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    #define ll long long 
    long long int count(int coins[], int N, int sum) {

        // code here.
        //coins[]=wt[]
        //sum = W
        //knapsack
        //unbounded
        
        ll int t[N+1][sum+1];
        
        for(int x=0;x<=sum;++x)
        t[0][x]=0;
        
        //y=0 just like the subset sum problem would also work
        for(int y=1;y<=N;++y)
        t[y][0]=1;
        
        
        for(int x=1;x<=N;++x)
        {
            for(int y=1;y<=sum;++y)
            {
                if(coins[x-1]<=y)
                {
                    t[x][y]=t[x][y-coins[x-1]]+t[x-1][y];
                }
                else
                t[x][y]=t[x-1][y];
                
            }
        }
        
        return t[N][sum];
        
    }
};

















//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends
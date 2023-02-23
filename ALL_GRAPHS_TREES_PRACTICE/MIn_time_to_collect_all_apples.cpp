//https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/submissions/876063632/
//https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/solutions/623673/concise-explanation-with-a-picture-for-visualization/?orderBy=most_votes

class Solution {
public:
    int dfs(vector<vector<int>> &adj,vector<bool> &hasApple,int node,int par,int childcost,int mycost)
    {
       
        for(auto &child:adj[node])
        {
            if(child==par)continue;
            childcost+=dfs(adj,hasApple,child,node,0,2);
        }

        if(childcost==0 && hasApple[node]==0)
        return 0;

        return childcost+mycost;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> store;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n-1;++i)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans=dfs(adj,hasApple,0,-1,0,0);

        return ans;
    }
};
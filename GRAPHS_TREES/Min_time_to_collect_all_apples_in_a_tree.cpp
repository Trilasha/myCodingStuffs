class Solution {
public:
    vector<int> store;
    vector<vector<int>> adj;
    int dfs(int node,int par,vector<bool> &hasApple)
    {
        int cnt=0;
        for(auto &child:adj[node])
        {
            if(child==par)continue;
            cnt+=dfs(child,node,hasApple);
        }

        if(node==0)
        return cnt;
        
        if(hasApple[node] || cnt!=0)
        return cnt+2;

        return cnt;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adj.resize(n,vector<int>());
        store.resize(n,0);
        for(int i=0;i<n-1;++i)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(0,-1,hasApple);


    }
};
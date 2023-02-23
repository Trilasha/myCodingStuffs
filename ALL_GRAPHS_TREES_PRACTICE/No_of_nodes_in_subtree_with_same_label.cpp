class Solution {
public:
    vector<int> store;
    vector<int> dfs(int node,int par,vector<vector<int>> &adj,string &labels)
    {
        vector<int> v(26,0);
        for(auto &child:adj[node])
        {
            if(child==par)continue;
            vector<int> temp=dfs(child,node,adj,labels);
            for(int i=0;i<26;++i)
            v[i]+=temp[i];
        }

        v[labels[node]-'a']++;
        store[node]=v[labels[node]-'a'];
        return v;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n+1);
        for(int i=0;i<edges.size();++i)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        store.resize(n,0);
        dfs(0,-1,adj,labels);

        return store;
    }
};
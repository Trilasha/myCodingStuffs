class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        //0-indexed graph
        vector<bool> vis(V,0);
        queue<int> q;
        q.push(0);
        vis[0]=1;
        vector<int> bfs;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto &child:adj[node])
            {
                if(!vis[child])
                {
                    vis[child]=1;
                    q.push(child);
                }
            }
        }
        return bfs;
    }
};
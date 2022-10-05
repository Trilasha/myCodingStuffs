//way1
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node,vector<int> adj[],vector<bool> &vis,vector<int> &store)
    {
        //vis[node]=1;
        //store.push_back(node);
        for(auto &child:adj[node])
        {
            if(!vis[child])
            {
                 vis[child]=1;
                 store.push_back(child);
                dfs(child,adj,vis,store);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> vis(V,0);
        int start =0;
        vector<int> store;
        vis[0]=1;
        store.push_back(0);
        dfs(start,adj,vis,store);
        return store;
    }
};


//way2
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node,vector<int> adj[],vector<bool> &vis,vector<int> &store)
    {
        vis[node]=1;
        store.push_back(node);
        for(auto &child:adj[node])
        {
            if(!vis[child])
            {
                 //vis[child]=1;
                 //store.push_back(child);
                dfs(child,adj,vis,store);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> vis(V,0);
        int start =0;
        vector<int> store;
        //vis[0]=1;
        //store.push_back(0);
        dfs(start,adj,vis,store);
        return store;
    }
};

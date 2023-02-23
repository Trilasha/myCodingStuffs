    
    //tc-->O(N+2E) + O(N)
    //sc-->O(N)+O(N)-->recursion stack + visited array
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int node,int parent,vector<int> adj[],vector<int> &vis)
    {
        vis[node]=1;
        for(auto &child:adj[node])
        {
            if(!vis[child])
            {
               if(dfs(child,node,adj,vis))
               return true;
            }
            else if(child!=parent)
            return true;
            
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int x=0;x<V;++x)
        {
           if(!vis[x])
           {
               if(dfs(x,-1,adj,vis))
               return true;
           }
        }
        return false;
    }
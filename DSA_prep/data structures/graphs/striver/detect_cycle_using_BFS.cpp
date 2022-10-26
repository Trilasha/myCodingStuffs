  public:
  //O-based node
  //Especially applicable for multiple connected components 
  

  //tc-->O(n+2e)
  //summation of adjacent nodes==summation of degrees == 2e in undirected graphs 
  
  
  //sc-->O(n)+O(n)-->queue+visited array-->O(n)
  
    // Function to detect cycle in an undirected graph.
    bool detect_cycle(int src,vector<int> adj[],vector<bool> &vis)
    {
        vis[src]=1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto &child:adj[node])
            {
                if(!vis[child])
                {
                    vis[child]=1;
                    q.push({child,node});
                }
                else if(parent!=child)
                return true;
            }
        }
        return false;
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V,0);
        for(int x=0;x<V;++x)
        {
            if(!vis[x])
            {
                if(detect_cycle(x,adj,vis))
                return true;
            }
        }
        return false;
        
    }
};
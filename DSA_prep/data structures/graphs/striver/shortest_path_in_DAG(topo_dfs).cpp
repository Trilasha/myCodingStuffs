class Solution {
  private:
  void toposort(int node,vector<vector<pair<int,int>>> &adj,vector<int> &vis,stack<int> &st)
  {
      vis[node]=1;
      
      for(auto &i:adj[node])
      {
          int child_node=i.first;
          if(!vis[child_node])
          toposort(child_node,adj,vis,st);
      }
      st.push(node);
      return;
  }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int,int>>> adj(N);
        for(int i=0;i<edges.size();++i)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
        }
        
        
        
    //toposort via dfs so stack is needed
    
    //tc-->O(N+M)(N-->no of vertices , M-->no of edges)
    vector<int> vis(N,0);
    stack<int> st;
    
    for(int i=0;i<N;++i)
    {
        if(!vis[i])
        toposort(i,adj,vis,st);
    }
    
    
    //creating the distance array
    vector<int> dist(N,1e9);
    dist[0]=0;
    
    //tc-->O(N+M)
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        for(auto &i:adj[node])
        {
            int u=i.first;
            int wt=i.second;
            if(dist[node]+wt<dist[u])
            dist[u]=dist[node]+wt;
        }
    }
    
    
    
    
    //additional thing added
    for(int i=0;i<N;++i)
    {
        if(dist[i]>=1e9)
        dist[i]=-1;
    }
    return dist;
     }
};
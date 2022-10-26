  //previous dfs algo for undirected ones would not work 
  //as if I found a visited node then it must be visited on the same path for a cycle to exit or else 
  //no cycle exits in that case
  
  //tc--> O(V+E) since directed graph
  //sc-->2n
  
    // Function to detect cycle in a directed graph.
    bool dfsCheck(int node,vector<int> &vis,vector<int> &pathVisited,vector<int> adj[])
    {
        vis[node]=1;
        pathVisited[node]=1;
        for(auto &child:adj[node])
        {
            if( vis[child] && pathVisited[child])
            return true;
            if(!vis[child])
            {
                // vis[child]=1;
                // pathVisited[child]=1;
                if(dfsCheck(child,vis,pathVisited,adj))
                return true;
            }
            //pathVisited[child]=0;
        }
        pathVisited[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> pathVisited(V,0);
        for(int i=0;i<V;++i)
        {
            if(dfsCheck(i,vis,pathVisited,adj))
            return true;
        }
        return false;
    }




////////////////////////////////////////////////////////////////// Using one visited array only(without pathVisited)////////////////////////////////////////////////////////////////////
 bool dfsCheck(int node,vector<int> &vis,vector<int> adj[])
    {
        vis[node]=2;
        // pathVisited[node]=1;
        for(auto &child:adj[node])
        {
            if( vis[child]==2)
            return true;
            if(!vis[child])
            {
                // vis[child]=1;
                // pathVisited[child]=1;
                if(dfsCheck(child,vis,adj))
                return true;
            }
            //pathVisited[child]=0;
        }
       vis[node]=1;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        //vector<int> pathVisited(V,0);
        for(int i=0;i<V;++i)
        {
            if(dfsCheck(i,vis,adj))
            return true;
        }
        return false;
    }
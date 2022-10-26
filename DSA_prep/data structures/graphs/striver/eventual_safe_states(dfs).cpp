
class Solution {
    private:
     bool dfsCheck(int node,vector<int> &vis,vector<int> &pathVisited,vector<int> adj[],vector<int> &check)
    {
        vis[node]=1;
        pathVisited[node]=1;
        check[node]=0;
        
        for(auto &child:adj[node])
        {
            if( vis[child] && pathVisited[child])
            {
            check[node]=0;
            return true;
            }
            
            if(!vis[child])
            {
                if(dfsCheck(child,vis,pathVisited,adj,check))
                {
                check[node]=0;
                return true;
                }
            }
        }
        check[node]=1;
        pathVisited[node]=0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> pathVisited(V,0);
        vector<int> check(V,0);
        vector<int> safeNodes;
        for(int i=0;i<V;++i)
        {
            if(!vis[i])
            {
                dfsCheck(i,vis,pathVisited,adj,check);
            }
        }
        for(int i=0;i<V;++i)
        {
            if(check[i]==1)
            {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};
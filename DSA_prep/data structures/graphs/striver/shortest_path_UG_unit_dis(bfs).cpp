class Solution {
    private:
    //////////////////meek/////////////////


    //tc-->O(V+2E-->similar to standard bfs
    //same node has to be visited again to check for the minimum distance hence no visited array is required as visited checking is not applicable 
    void bfs(int node,vector<vector<int>> &adj,vector<int> &dis)
    {
        //vis[node]=1;
       queue<int> q; 
       q.push(node);
       
       while(!q.empty())
       {
           int n=q.front();
           q.pop();
           for (auto &i:adj[n])
           {
               if(dis[n]+1<dis[i])
               {
               dis[i]=dis[n]+1;
               q.push(i);
              //vis[i]=1;
               }
           }
       }
       
    }
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<vector<int>> adj(N);
        for(auto &i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        
        vector<int> dis(N,1e9);
        dis[src]=0;
        vector<int> vis(N,0);
        
        for(int i=0;i<N;++i)
        {
            //if(!vis[i])-->may be given this line no issues 
            bfs(i,adj,dis);
        }
        
       for(int i=0;i<dis.size();++i)
       {
           if(dis[i]==1e9)
           dis[i]=-1;
       }
        
        return dis;
    }
};







/////////////////////////////////////////////////////   STRIVER'S CODE   /////////////////////////////////////////////////////////
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    //Create an adjacency list of size N for storing the undirected graph.
        vector<int> adj[N]; 
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]); 
            adj[it[1]].push_back(it[0]); 
        }

        //A dist array of size N initialised with a large number to 
        //indicate that initially all the nodes are untraversed.    
    
        int dist[N];
        for(int i = 0;i<N;i++) dist[i] = 1e9;
        // BFS Implementation.
        dist[src] = 0; 
        queue<int> q;
        q.push(src); 
        while(!q.empty()) {
            int node = q.front(); 
            q.pop(); 
            for(auto it : adj[node]) {
                if(dist[node] + 1 < dist[it]) {
                    dist[it] = 1 + dist[node]; 
                    q.push(it); 
                }
            }
        }
        // Updated shortest distances are stored in the resultant array ‘ans’.
        // Unreachable nodes are marked as -1. 
        vector<int> ans(N, -1);
        for(int i = 0;i<N;i++) {
            if(dist[i] != 1e9) {
                ans[i] = dist[i]; 
            }
        }
        return ans; 
    }
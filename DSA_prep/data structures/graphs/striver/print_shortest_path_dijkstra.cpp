 public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &i:edges)
        {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        
       
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int> dis(n+1,1e9);
        vector<int> parent(n+1);
        
        
        for(int i=1;i<=n;++i)
        parent[i]=i;
        
        dis[1]=0;
        pq.push({0,1});
        
        while(!pq.empty())
        {
            int distance=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto &i:adj[node])
            {
                int childNode=i.first;
                int edgeWeight=i.second;
                if(distance+edgeWeight<dis[childNode])
                {
                    dis[childNode]=distance+edgeWeight;
                    pq.push({dis[childNode],childNode});
                    parent[childNode]=node;
                }
            }
        }
        
        if(dis[n]==1e9)
        return {-1};
        
        vector<int> ans;
        int tNode=n;
        
        ans.push_back(tNode);
        while(parent[tNode]!=tNode)
        {
            ans.push_back(parent[tNode]);
            tNode=parent[tNode];
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
//set can be used to delete the already existing paths however there will be an introductin of logn for the set erase operation so the time complexity will not be much so unaffected can be said
//since erase operation is not avaialble in priority queues







	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    // priority_queue <ll, vector<ll>, greater<ll> > pq; 
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       
       set<pair<int,int>> s;
        vector<int> dis(V,1e9);
        
        dis[S]=0;
        s.insert({0,S});
        
        while(!s.empty())
        {
            auto it = *s.begin();
            int distance=it.first;
            int node=it.second;
            s.erase(*s.begin());
            for(auto &i:adj[node])
            {
                int childNode=i[0];
                int edgeWeight=i[1];
                if(distance+edgeWeight<dis[childNode])
                {
                    if(dis[childNode]!=1e9)
                    {
                        s.erase({dis[childNode],childNode});
                    }
                    dis[childNode]=distance+edgeWeight;
                    s.insert({dis[childNode],childNode});
                }
            }
        }
        return dis;
    }
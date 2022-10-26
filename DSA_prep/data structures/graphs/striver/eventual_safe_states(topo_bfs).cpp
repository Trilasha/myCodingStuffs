public:

//tc-->similar to toposort bfs
//sc-->similar to toposort bfs but with an addition of the reversed adjancency list and the sorting time period
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<vector<int>> newAdj(V);
        // for(auto &i:adj)-->throwing error
        
        //reversing the edges
        for(int i=0;i<V;++i)
        {
            for(auto &j:adj[i])
            {
                newAdj[j].push_back(i);
            }
        }
        
        
        //applying the basic toposort bfs algorithm
        vector<int> indegree(V,0);
        vector<int> topo;
	    for(auto &i:newAdj)
	    {
	        for(auto &j:i)
	        indegree[j]++;
	    }
	    
	    queue<int> q;
	    for(int i=0;i<V;++i)
	    {
	        if(indegree[i]==0)
	        q.push(i);
	    }
	
	
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto &i:newAdj[node])
	        {
	            indegree[i]--;
	            if(indegree[i]==0)
	            q.push(i);
	        }
	    }
	    sort(topo.begin(),topo.end());
	    return topo;
    }
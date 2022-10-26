public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<vector<int>> adjList(N);
	    for(auto &i:prerequisites)
	    {
	        adjList[i.second].push_back(i.first);
	    }
	    
	    //using toposort bfs to detect the presence of a cycle
	    vector<int> indegree(N,0);
	    for(auto &i:adjList)
	    {
	        for(auto &j:i)
	        indegree[j]++;
	    }
	    
	    queue<int> q;
	    for(int i=0;i<N;++i)
	    {
	        if(indegree[i]==0)
	        q.push(i);
	    }
	    
	    vector<int> topo;
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto &i:adjList[node])
	        {
	            indegree[i]--;
	            if(indegree[i]==0)
	            q.push(i);
	        }
	    }
	    
	    if(topo.size()==N)
	    return true;
	    else
	    return false;
	}
};
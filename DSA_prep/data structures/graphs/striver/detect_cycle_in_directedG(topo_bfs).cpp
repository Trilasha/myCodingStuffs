  public:
    // Function to detect cycle in a directed graph.

    //tc-->v+e
    //sc-->n
    //topo sort and bfs
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
         vector<int> indegree(V,0);
	    for(int i=0;i<V;++i)
	    {
	        for(auto &node:adj[i])
	        indegree[node]++;
	    }
	    
	    
	    queue<int> q;
	    vector<int> topo;
	    
	    for(int i=0;i<V;++i)
	    {
	        if(indegree[i]==0)
	        q.push(i);
	    }
	    
	    //since it's a DAG so some node will always be there in the queue
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto &child:adj[node])
	        {
	            indegree[child]--;
	            if(indegree[child]==0)
	            q.push(child);
	        }
	    }
	    
	    //upto this part is the code for topological sort
	    if(topo.size()==V)
	    return false;
	    else
	    return true;
    }
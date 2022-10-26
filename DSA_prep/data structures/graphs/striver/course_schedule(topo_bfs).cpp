
class Solution
{
  public:
    vector<int> findOrder(int N, int m, vector<vector<int>> prerequisites) 
    {
        vector<vector<int>> adjList(N);
	    for(auto &i:prerequisites)
	    {
	        adjList[i[1]].push_back(i[0]);
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
	    return topo;
	    else
	    return {};
    }
};
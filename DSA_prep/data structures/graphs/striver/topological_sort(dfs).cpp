{
	public:
	//Function to return list containing vertices in Topological order. 
	
	//sc-->O(n)
	//tc-->O(V+E)-->similar to the dfs tc for directed graphs
	
	void dfs(int node,vector<int> &vis,vector<int> adj[],stack<int> &s)
	{
	    vis[node]=1;
	    for(auto &i:adj[node])
	    {
	        if(!vis[i])
	        {
	            dfs(i,vis,adj,s);
	        }
	    }
	    s.push(node);
	    return;
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> vis(V,0);
	    stack<int> s;
	    for(int i=0;i<V;++i)
	    {
	        if(!vis[i])
	        {
	            dfs(i,vis,adj,s);
	        }
	    }
	vector<int> ans;
	while(!s.empty())
	{
	    ans.push_back(s.top());
	    s.pop();
	}
	return ans;
	}
};
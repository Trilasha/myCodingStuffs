public:

//tc and sc similar to dfs
bool dfs(int start,vector<int> &color,vector<int> adj[])
{
	        for(auto &i:adj[start])
	        {
	            if(color[i]==color[start])
	            return false;
	            if(color[i]==-1)
	            {
	                color[i]=!color[start];
	               if(dfs(i,color,adj)==false)
	               return false;
	            }
	        }
	    return true;
}

	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V,-1);
	    for(int i=0;i<V;++i)
	    {
	        if(color[i]==-1)
	        {
	              color[i]=0;
	            if(dfs(i,color,adj)==0)
	            return false;
	        }
	    }
	    return true;
	    
	}
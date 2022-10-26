//////////////////meek

public:
//tc-->similar to bfs
//sc-->similar to bfs
bool bfs(int start,vector<int> &color,vector<int> adj[])
{
        queue<pair<int,int>> q;
	    q.push({start,0});
	    while(!q.empty())
	    {
	        int node=q.front().first;
	        int clr=q.front().second;
	        q.pop();
	        for(auto &i:adj[node])
	        {
	            if(color[i]==clr)
	            return false;
	            if(color[i]==-1)
	            {
	                if(clr==0)
	                {
	                    color[i]=1;
	                    q.push({i,1});
	                }
	                else
	                {
	                    color[i]=0;
	                    q.push({i,0});
	                }
	            }
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
	            if(bfs(i,color,adj)==0)
	            return false;
	        }
	    }
	    return true;
	    
	}



///////////////////////////////////////////////////////////////////////////////////////////////////// striver
bool bfs(int start,vector<int> &color,vector<int> adj[])
{
        queue<int> q;
	    q.push(start);
	    color[start]=0;
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        for(auto &i:adj[node])
	        {
	            if(color[i]==color[node])
	            return false;
	            if(color[i]==-1)
	            {
	                color[i]=!color[node];
	                q.push(i);
	            }
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
	            if(bfs(i,color,adj)==0)
	            return false;
	        }
	    }
	    return true;
	    
	}
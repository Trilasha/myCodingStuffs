{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>> vis(n,vector<int>(m,0));
	    vector<vector<int>> dis(n,vector<int>(m,0));
	    queue<pair<pair<int,int>,int>> q;
	    
	    //inserting all the initial ones in the queue
	    for(int i=0;i<n;++i)
	    {
	        for(int j=0;j<m;++j)
	        {
	            if(grid[i][j]==1)
	            {
	                vis[i][j]=1;
	                q.push({{i,j},0});
	            }
	        }
	    }
	    
	    //
	    while(!q.empty())
	    {
	        int r=q.front().first.first;
	        int c=q.front().first.second;
	        int steps=q.front().second;
	        
	        dis[r][c]=steps;
	        q.pop();
	        
	        //
	        vector<int> delrow={0,-1,0,+1};
	        vector<int> delcol={-1,0,+1,0};
	        
	        for(int i=0;i<4;++i)
	        {
	            int nrow=r+delrow[i];
	            int ncol=c+delcol[i];
	            
	            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0)
	            {
	                vis[nrow][ncol]=1;
	                q.push({{nrow,ncol},steps+1});
	            }
	        }
	    }
	    return dis;
	}
};
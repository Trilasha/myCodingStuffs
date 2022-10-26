//////////////////////////
/*
//bfs has been used
TC--> O(n*m)
SC--> O(n*m)
*/
//////////////////////////



{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int cntfresh=0;
        int ct=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else if(grid[i][j]==1)
                cntfresh++;
            }
        }
        //
        int time=0;
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int curr_tm=q.front().second;
            q.pop();
            time=max(time,curr_tm);
            
            //
            vector<int> delrow={0,-1,0,+1};
            vector<int> delcol={-1,0,+1,0};
            
            //
            for(int x=0;x<4;++x)
            {
                int nrow=r+delrow[x];
                int ncol=c+delcol[x];
                //
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1)
                {
                    q.push({{nrow,ncol},curr_tm+1});
                    vis[nrow][ncol]=2;
                    ct++;
                }
            }
            
        }
        
        //check
        if(ct!=cntfresh)
        return -1;
        
        return time;
    }
};





////////////////////////////////////////////////////////////   ANOTHER APPROACH    //////////////////////////////////////////////////////////////////
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
       // int cntfresh=0;
       // int ct=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                // else if(grid[i][j]==1)
                // cntfresh++;
            }
        }
        //
        int time=0;
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int curr_tm=q.front().second;
            q.pop();
            time=max(time,curr_tm);
            
            //
            vector<int> delrow={0,-1,0,+1};
            vector<int> delcol={-1,0,+1,0};
            
            //
            for(int x=0;x<4;++x)
            {
                int nrow=r+delrow[x];
                int ncol=c+delcol[x];
                //
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1)
                {
                    q.push({{nrow,ncol},curr_tm+1});
                    vis[nrow][ncol]=2;
                    //ct++;
                }
            }
            
        }
        
        //check
        // if(ct!=cntfresh)
        // return -1;
        
        // return time;
        
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(vis[i][j]!=2 && grid[i][j]==1)
                return -1;
            }
        }
        return time;
    }
};
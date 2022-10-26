
class Solution {
  private:
  //tc-->nm
  //sc-->nm
  void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>> &grid,vector<pair<int,int>> &vp,int base_row,int base_col)
  {
      queue<pair<int,int>> q;
      q.push({row,col});
      
      vis[row][col]=1;
      
      int r_row=row-base_row;
      int c_col=col-base_col;
      vp.push_back({r_row,c_col});
      
      int n=grid.size();
      int m=grid[0].size();
      
      while(!q.empty())
      {
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        vector<int> delrow={0,-1,0,+1};
        vector<int> delcol={-1,0,+1,0};
	        for(int i=0;i<4;++i)
	        {
	            int nrow=r+delrow[i];
	            int ncol=c+delcol[i];
	            
	            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1)
	            {
	              q.push({nrow,ncol});
	              int r_r=nrow-base_row;
	              int c_c=ncol-base_col;
	              vp.push_back({r_r,c_c});
	              vis[nrow][ncol]=1;
	            }
	        }
      }
  }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> s;
        
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    vector<pair<int,int>> vp;
                    for(auto &k:vp)
                    cout<<k.first<<" "<<k.second<<endl;
                    bfs(i,j,vis,grid,vp,i,j);
                    s.insert(vp);
                }
            }
        }
        return s.size();
        
    }
};

class Solution {
  public:
  
  //meek
  //using dfs
  //tc-->nm
  //sc-->nm
  void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>> &grid)
  {
      vis[row][col]=1;
      int n=grid.size();
      int m=grid[0].size();
      vector<int> delrow={0,-1,0,+1};
      vector<int> delcol={-1,0,+1,0};
	        
	        for(int i=0;i<4;++i)
	        {
	            int nrow=row+delrow[i];
	            int ncol=col+delcol[i];
	            
	            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1)
	            {
	                //vis[nrow][ncol]=1;
	              dfs(nrow,ncol,vis,grid);
	            }
	        }
      
  }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        // queue<pair<int,int>> q;
       for(int i=0;i<n;++i)
       {
           if(grid[i][0]==1)
           {
               dfs(i,0,vis,grid);
           }
           if(grid[i][m-1]==1)
           {
               dfs(i,m-1,vis,grid);
           }
       }
        for(int i=0;i<m;++i)
       {
           if(grid[0][i]==1)
           {
               dfs(0,i,vis,grid);
               
           }
            if(grid[n-1][i]==1)
           {
               dfs(n-1,i,vis,grid);
           }
           
       }
       
       int ct=0;
       
       for(int i=0;i<n;++i)
       {
           for(int j=0;j<m;++j)
           {
               if(grid[i][j]==1 && !vis[i][j])
               ct++;
           }
       }
       return ct;
    }
};
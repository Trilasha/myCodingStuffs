
class Solution{
public:
//tc-->nm
//sc-->nm


void dfs(int row,int col,vector<vector<char>> &mat,vector<vector<int>> &vis)
{
    vis[row][col]=1;
    
    int n=mat.size();
    int m=mat[0].size();
    vector<int> delrow={0,-1,0,+1};
	vector<int> delcol={-1,0,+1,0};
	        
	        for(int i=0;i<4;++i)
	        {
	            int nrow=row+delrow[i];
	            int ncol=col+delcol[i];
	            
	            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && mat[nrow][ncol]=='O')
	            {
	                vis[nrow][ncol]=1;
	                dfs(nrow,ncol,mat,vis);
	            }
}
}
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<m;++i)
        {
            if(!vis[0][i] && mat[0][i]=='O')
            dfs(0,i,mat,vis);
            if(!vis[n-1][i] && mat[n-1][i]=='O')
            dfs(n-1,i,mat,vis);
        }
        
        
        for(int i=0;i<n;++i)
        {
            if(!vis[i][0] && mat[i][0]=='O')
            dfs(i,0,mat,vis);
            if(!vis[i][m-1] && mat[i][m-1]=='O')
            dfs(i,m-1,mat,vis);
        }
        
        vector<vector<char>> copy=mat;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(copy[i][j]=='O' && !vis[i][j])
                copy[i][j]='X';
            }
        }
        return copy;
        
    }
};
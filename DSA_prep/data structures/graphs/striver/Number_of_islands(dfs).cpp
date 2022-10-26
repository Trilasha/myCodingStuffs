//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int st,int to,vector<vector<int>> &vis,vector<vector<char>> &grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        vis[st][to]=1;
        // queue<pair<int,int>> q;
        // q.push({st,to});
        
        // while(!q.empty())
        // {
            // int row=q.front().first;
            // int col=q.front().second;
            // q.pop();
            int row=st;
            int col=to;
            for(int delrow=-1;delrow<=1;++delrow)
            {
                for(int delcol=-1;delcol<=1;++delcol)
                {
                    int nrow=row+delrow;
                    int ncol=col+delcol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol])
                    {
                        vis[nrow][ncol]=1;
                       // q.push({nrow,ncol});
                       dfs(nrow,ncol,vis,grid);
                    }
                }
            }
        //}
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ct=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                 ct++;
                 dfs(i,j,vis,grid);
                }
            }
        }
        return ct;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
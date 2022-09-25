class Solution {
  public:
    vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries) {
        // Code here
        vector<vector<int>> v(n,vector<int>(n,0));
        for(auto &it:Queries)
        {
            for(int i=it[0];i<=it[2];++i)
            {
               v[i][it[1]]++;
               if(it[3]+1<n)
               v[i][it[3]+1]--;
            }
        }
        
        for(int col=1;col<n;++col)
        {
            for(int row=0;row<n;++row)
            {
                v[row][col]+=v[row][col-1];
            }
        }
        return v;
    }
};
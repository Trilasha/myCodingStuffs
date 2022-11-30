class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        map<int,int> row_one;
        map<int,int> row_zero;
        map<int,int> col_one;
        map<int,int> col_zero;
        
        int one=0;
        int zero=0;
        
        //rows
        for(int i=0;i<r;++i)
        {
            zero=0;
            one=0;
            for(int j=0;j<c;++j)
            {
                if(grid[i][j]==0)
                    zero++;
                else
                    one++;
            }
            row_one[i]=one;
            row_zero[i]=zero;
        }
        
          //cols
        for(int i=0;i<c;++i)
        {
            zero=0;
            one=0;
            for(int j=0;j<r;++j)
            {
                if(grid[j][i]==0)
                    zero++;
                else
                    one++;
            }
            col_one[i]=one;
            col_zero[i]=zero;
        }
        
        
        vector<vector<int>> ans(r,vector<int>(c,0));
        
        for(int i=0;i<r;++i)
        {
            for(int j=0;j<c;++j)
            {
                ans[i][j]=row_one[i]+col_one[j]-row_zero[i]-col_zero[j];
            }
        }
        
        return ans;
    }
};
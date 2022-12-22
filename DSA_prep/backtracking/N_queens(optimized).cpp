
class Solution {
public:
    //O(N) approach :- (OPTIMIZED)

    void solve(int col,vector<string> &board,vector<vector<string>> &ans,int n,vector<int> &left,vector<int> &left_lower_diagonal,vector<int> &left_upper_diagonal)
    {
        if(n==col)
        //found a valid chess config
        {
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;++row)
        {   ///
            if(left[row]==0 && left_lower_diagonal[row+col]==0 && left_upper_diagonal[n-1+col-row]==0)
            {
                board[row][col]='Q';
                left[row]=1;
                left_lower_diagonal[row+col]=1;
                left_upper_diagonal[n-1 + col-row]=1;
                solve(col+1,board,ans,n,left,left_lower_diagonal,left_upper_diagonal);

                //backtracking to remove the queen so as to try for other alternatives(if any)
                board[row][col]='.';
                left[row]=0;
                left_lower_diagonal[row+col]=0;
                left_upper_diagonal[n-1 + col-row]=0;
            }
        }
    }






    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<string> board(n);
        //to initialze a string with a particular character
        string s(n,'.');

        for(int i=0;i<n;++i)
        {
            board[i]=s;
        }

        /// 
        vector<int> left(n);
        vector<int> left_lower_diagonal(2*n-1);
        vector<int> left_upper_diagonal(2*n-1);
        solve(0,board,ans,n,left,left_lower_diagonal,left_upper_diagonal);
        return ans;
    }
};
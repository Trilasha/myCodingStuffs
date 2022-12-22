class Solution {
public:
    ///////////////////////////////////////////// O(N^2) approach /////////////////////////////////////////////


    bool isSafe(int row,int col,vector<string> &board,int n)
    {
        //out of the 8 possibilities it is enough to check for the below 3(reason stated already)
        int dup_row=row;
        int dup_col=col;

        //left
        while(col>=0)
        {
            if(board[row][col]=='Q')
            return false;
            col--;
        }

        col=dup_col;
        //lower diagonal left
        while(row<n && col>=0)
        {
            if(board[row][col]=='Q')
            return false;
            row++;
            col--;
        }


        row=dup_row;
        col=dup_col;
        //upper diagonal left
        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q')
            return false;
            row--;
            col--;
        }


        return true;
    }




    void solve(int col,vector<string> &board,vector<vector<string>> &ans,int n)
    {
        if(n==col)
        //found a valid chess config
        {
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;++row)
        {
            if(isSafe(row,col,board,n))
            {
                board[row][col]='Q';
                solve(col+1,board,ans,n);

                //backtracking
                board[row][col]='.';
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


        solve(0,board,ans,n);
        return ans;
    }
};




/*#########################################################################################################################################*/

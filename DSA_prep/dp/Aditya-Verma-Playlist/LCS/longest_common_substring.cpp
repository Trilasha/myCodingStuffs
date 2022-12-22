/*
Time Complexity: O(m*n) 
Auxiliary Space: O(m*n), since m*n extra space has been taken.
*/




class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        int t[n+1][m+1];
        
        for(int x=0;x<=n;++x)
        t[x][0]=0;
        
        for(int y=0;y<=m;++y)
        t[0][y]=0;
        
        for(int x=1;x<=n;++x)
        {
            for(int y=1;y<=m;++y)
            {
                if(S1[x-1]==S2[y-1])
                t[x][y]=1+t[x-1][y-1];
                else
                t[x][y]=0;
            }
        }
        
        int max_val=0;
        
        for(int x=1;x<=n;++x)
        {
            for(int y=1;y<=m;++y)
            {
                max_val=max(max_val,t[x][y]);
            }
        }
        
        return max_val;
    }
};
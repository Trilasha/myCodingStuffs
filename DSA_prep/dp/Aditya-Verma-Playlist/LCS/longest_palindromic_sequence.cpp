/*
//string a;
//lps(a)=lcs(a,reverse(a));


// abcdead
// daedcba



https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/
*/
//----------------------------------------------------------------------------------------------------------------------------------------------


int longestPalinSubseq(string A) {
        //code here
        string one=A;
        reverse(A.begin(),A.end());
        string two=A;
        
        //find the lcs of both the strings 
        
        int sz1=one.size();
        int sz2=two.size();
        
        int dp[sz1+1][sz2+1];
        
        for(int i=0;i<=sz1;++i)
        dp[0][i]=0;
        
        for(int i=0;i<=sz2;++i)
        dp[i][0]=0;
        
        for(int i=1;i<=sz1;++i)
        {
            for(int j=1;j<=sz2;++j)
            {
                if(one[i-1]==two[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[sz1][sz2];
    }
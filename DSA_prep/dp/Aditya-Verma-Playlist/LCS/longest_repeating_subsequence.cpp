/*
https://www.geeksforgeeks.org/longest-repeated-subsequence/

code exactly same as the lcs just add the condition check of (i!=j)
*/


int longestRepeatingSubsequence(string text) {
        int n=text.size();
        string text2=tex1;
        int m=text2.size();


        for(int i=0;i<=n;++i)
        dp[0][i]=0;
        
        for(int i=0;i<=m;++i)
        dp[i][0]=0;

        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                if(text1[i-1] == text2[j-1] && i!=j)
                dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[n][m];
    }
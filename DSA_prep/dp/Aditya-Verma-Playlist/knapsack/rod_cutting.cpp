/*
https://practice.geeksforgeeks.org/problems/rod-cutting0840/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

https://www.geeksforgeeks.org/cutting-a-rod-dp-13/

*/


  int cutRod(int price[], int n) {
        //code here
        //wt val max_wt
        //length profit max_length
        
        //int dp[given_array(price/wt)_length+1][max_length+1]
        //here 'price' array length and 'length' array size is equal
        
        int length[n+1];
        for(int i=0;i<n;++i)
        length[i]=i+1;
        
        
        int dp[n+1][n+1];
        
        for(int i=0;i<=n;++i)
        dp[i][0]=0;
        
        for(int i=0;i<=n;++i)
        dp[0][i]=0;
        
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(length[i-1]<=j)
                dp[i][j]=max(price[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[n][n];
    }
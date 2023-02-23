/*
https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/

*/

//recursive 
 int longestCommonSubsequence(string text1, string text2,int s1,int s2) {
        if( s1==0 && s2==0 )
        return 0;

        if(text1[s1-1]==text2[s2-1])
        return 1+longestCommonSubsequence(text1,text2,s1-1,s2-1);
        else
        return max(longestCommonSubsequence(text1,text2,s1-1,s2),longestCommonSubsequence(text1,text2,s1,s2-1));
    }






//memoization (top-down)

class Solution {
public:
    int dp[1001][1001];
    int LCS_helper(string text1,string text2,int s1,int s2)
    {
        if(s1==0 || s2==0)
        return 0;

        if(dp[s1][s2]!=-1)
        return dp[s1][s2];

        if(text1[s1-1]==text2[s2-1])
        return dp[s1][s2]=1+LCS_helper(text1,text2,s1-1,s2-1);
        else
        return dp[s1][s2]=max(LCS_helper(text1,text2,s1-1,s2),LCS_helper(text1,text2,s1,s2-1));

       // return dp[s1][s2];
    }


    int longestCommonSubsequence(string text1, string text2) {
         memset(dp,-1,sizeof(dp));
         int s1=text1.size();
         int s2=text2.size();
         return LCS_helper(text1,text2,s1,s2);
    }
};














//checkout the link given at the top 
//bottomup
class Solution {
public:
    //int dp[1002][1002];
    int LCS_helper(string text1,string text2,int s1,int s2)
    {
      int dp[s1+1][s2+1];
    
      for(int x=0;x<=s2;++x)
      dp[0][x]=0;

      for(int y=0;y<=s1;++y)
      dp[y][0]=0;

      for(int x=1;x<=s1;++x)
      {
          for(int y=1;y<=s2;++y)
          {
              if(text1[x-1]==text2[y-1])
              dp[x][y]=1+dp[x-1][y-1];
              else
              dp[x][y]=max(dp[x-1][y],dp[x][y-1]);
          }
      }

      return dp[s1][s2];
    }


    int longestCommonSubsequence(string text1, string text2) {
         //memset(dp,-1,sizeof(dp));
         int s1=text1.size();
         int s2=text2.size();
         return LCS_helper(text1,text2,s1,s2);
    }
};


















//bottom-up approach 
  int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();

        int dp[n+1][m+1];

        for(int i=0;i<=n;++i)
        dp[0][i]=0;

        for(int i=0;i<=n;++i)
        dp[i][0]=0;


        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                if(text1[i-1] == text2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[n][m];
    }
//memoization
class Solution{
public:
    bool isPalindrome(string &s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i]!=s[j])
            return false;
            i++;
            j--;
        }
        
        return true;
    }
    int recur(string &s,int i,int j,vector<vector<int>> &dp)
    {
        if(i>=j)
        return dp[i][j]=0;
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        if(isPalindrome(s,i,j))
        return dp[i][j]=0;
        
        
        int ans=INT_MAX;
        for(int k=i;k<=j-1;++k)
        {
            int temp=recur(s,i,k,dp)+recur(s,k+1,j,dp)+1;
            //for further optimization
            //int temp=((dp[i][k]!=-1)?dp[i][k]:recur(s,i,k,dp))+((dp[k+1][j]!=-1)?dp[k+1][j]:recur(s,k+1,j,dp))+1;
            ans=min(ans,temp);
        }
        
        
        return dp[i][j]=ans;
    }
    int palindromicPartition(string str)
    {
        int n=str.size();
        int i=0;
        int j=n-1;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        recur(str,i,j,dp);
        
        return dp[0][n-1];
    }
};





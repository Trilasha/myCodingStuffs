// problem link --> https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=1
//recursion

int func(n)
{
    if(n==0)
    return 0;

    int left=func(n-1)+abs(val[n]-val[n-1]);
    if(n>1)
    int right=func(n-2)+abs(val[n]-val[n-2]);

    return min(left,right);
}









//topdown
#include <bits/stdc++.h>

int solve(int n,vector<int> &heights,vector<int> &dp)
{
    if(n<=1)return 0;

    if(dp[n]!=-1)
    return dp[n];

    int ans;

    int left=solve(n-1, heights,dp)+abs(heights[n-1]-heights[n-2]);
    ans=left;
    if (n > 2) {
      int right = solve(n - 2, heights,dp) + abs(heights[n - 1] - heights[n - 3]);
      ans=min(left,right);
    }

    return dp[n]=ans;
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    solve(n,heights,dp);


    return dp[n];


}







//bottomup--> meek
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    int dp[n+1];

    dp[0]=0;
    dp[1]=0;
    dp[2]=abs(heights[1]-heights[0]);

    for(int i=3;i<=n;++i)
    {
        dp[i]=min(abs(heights[i-1]-heights[i-3])+dp[i-2],abs(heights[i-1]-heights[i-2])+dp[i-1]);
    }


    return dp[n];


}












//space optimized bottomup
#include <bits/stdc++.h>


int frogJump(int n, vector<int> &heights)
{
    int prev=0;
    int prevprev=0;
    int curr;
    for(int i=2;i<=n;++i)
    {
        if(i>2)
        curr=min(abs(heights[i-1]-heights[i-3])+prevprev,abs(heights[i-1]-heights[i-2])+prev);
        else
        curr=abs(heights[i-1]-heights[i-2])+prev;
        
        prevprev=prev;
        prev=curr;
    }


    return prev;
}
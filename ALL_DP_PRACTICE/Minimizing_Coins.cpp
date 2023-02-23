#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,sum;
    cin>>n>>sum;

    vector<int> v(n);
    for(auto &i:v)
    cin>>i;

    int dp[n+1][sum+1];

    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=sum;++j)
           dp[i][j]=INT_MAX-1;
    }

    for(int i=0;i<=sum;++i)
    dp[0][i]=INT_MAX-1;

    for(int i=1;i<=n;++i)
    dp[i][0]=0;

    for(int i=0;i<=sum;++i)
    {
        if(i%v[0])
        dp[1][i]=i/v[0];
        else
        dp[1][i]=INT_MAX-1;
    }

    for(int i=2;i<=n;++i)
    {
        for(int j=0;j<=sum;++j)
        {
            if(v[i-1]<=j)
            dp[i][j]=min(1+dp[i][j-v[i-1]],dp[i-1][j]);
            else
            dp[i][j]=dp[i-1][j];
        }
    }

    if(dp[n][sum]==(INT_MAX-1))
    cout<<-1<<endl;
    else
    cout<<dp[n][sum]<<endl;
    return 0;
}
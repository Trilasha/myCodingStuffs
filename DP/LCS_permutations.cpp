#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll lcs(vector<ll> &s1, vector<ll> &s2)
{
    ll n = s2.size();
    ll db[n + 1] = {}; 
 

    for (int i = 1; i <= n; ++i) {
        int prev = db[0];
        for (int j = 1; j <= n; ++j) {
            int temp = db[j];
            if (s1[i - 1] == s2[j - 1])
                db[j] = 1 + prev;
            else
                db[j] = max(db[j - 1], db[j]);
            prev = temp;
        }
    }
 
    return db[n];
}
int main()
{
    ll n;
    cin>>n;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;++i)
    cin>>a[i];

    for(int i=0;i<n;++i)
    cin>>b[i];

    // vector<vector<ll>> dp(2,vector<ll>(n+1,0));
    // bool chk;

    // for(ll i=0;i<=n;++i)
    // {
    //     chk=i&1;
    //     for(ll j=0;j<=n;++j)
    //     {
    //         if(i==0 || j==0)
    //         dp[chk][j]=0;
    //         else if(a[i-1]==b[j-1])
    //         dp[chk][j]=1+dp[1-chk][j-1];
    //         else
    //         dp[chk][j]=max(dp[1-chk][j],dp[chk][j-1]);
    //     }
    // }


    cout<<lcs(a,b)<<endl;


    return 0;
}
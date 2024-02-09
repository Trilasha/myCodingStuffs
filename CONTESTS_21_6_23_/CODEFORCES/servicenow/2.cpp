#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    ll n;
    cin>>n;
    vector<vector<ll>> v(n,vector<ll>(n)),dp(n,vector<ll>(n,1e17));
    vector<pair<ll,ll>> dxy={{-1,0},{1,0},{0,-1},{0,1}};
    priority_queue<pair<ll,array<ll,2>>,vector<pair<ll,array<ll,2>>>,greater<pair<ll,array<ll,2>>>> q;
    for(ll i=0;i<n;++i){
        for(ll j=0;j<n;++j){
            cin>>v[i][j];
            if(v[i][j]==2){
                q.push({0,{i,j}});
                // cout<<dp[i][j]<<endl;
            }
        }
    }
    ll ans=-1;
    while(!q.empty()){
        auto it=q.top();
        q.pop();
        ll x=it.second[0],y=it.second[1],d=it.first;
        if(dp[x][y]<=d){
            continue;
        }
        dp[x][y]=d;
        for(auto p:dxy){
            ll nx=x+p.first,ny=y+p.second;
            if(nx<0||nx>=n||ny<0||ny>=n){
                continue;
            }
            if(v[nx][ny]==1 && dp[nx][ny]>(d+1)){
                // cout<<x<<" "<<y<<" "<<dp[x][y]<<endl;
                dp[nx][ny]=d+1;
                q.push({d+1,{nx,ny}});
            }
        }
    }
    ll ok=0;
    for(ll i=0;i<n;++i){
        for(ll j=0;j<n;++j){
            if(v[i][j]==1){
              cout<<dp[i][j]<<endl;
              ans=max(ans,dp[i][j]);
            }
        }
    }
    cout<<((ans==1e17)?-1:ans)<<endl;
    return 0;
}
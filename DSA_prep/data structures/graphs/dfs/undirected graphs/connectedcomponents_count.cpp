#include <bits/stdc++.h>
using namespace std;
#define ll long long

//const ll N=1e9+10;-->error because such a large sized array is not allowed
const ll N=1e5+10;
vector<ll> g[N];
bool visited[N];
void dfs(ll vertex)
{
    visited[vertex]=1;
    for(ll child: g[vertex])
    {
        if (visited[child])
        continue;
        dfs(child);
    }
}
int main()
{
ll n,e;
cin>>n>>e;
for (ll i = 0; i < e; ++i)
{
   ll x,y;
   cin>>x>>y;
   g[x].push_back(y);
   g[y].push_back(x);
}
ll ct=0;
for (ll i = 1; i <=n; ++i)
{
    if(visited[i])
    continue;
    dfs(i);
    ct++;
}
cout<<ct<<endl;
    return 0;
}
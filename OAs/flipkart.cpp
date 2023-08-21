#include<bits/stdc++.h>
using namespace std;

#define ll long long 

vector<ll> dijkstra(vector<vector<pair<ll,ll>>> &adj,ll n,ll S){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> dis(n + 1, 1e18);
    vector<ll> parent(n + 1);
 
    for (ll i = 1; i <= n; ++i)
        parent[i] = i;
 
    dis[S] = 0;
    pq.push({0, S});
 
    while (!pq.empty())
    {
        ll distance = pq.top().first;
        ll node = pq.top().second;
        pq.pop();

        if(distance>dis[node]) continue;

        for (auto &i : adj[node])
        {
            ll childNode = i.first;
            ll edgeWeight = i.second;
            if (distance + edgeWeight < dis[childNode])
            {
                dis[childNode] = distance + edgeWeight;
                pq.push({dis[childNode], childNode});
                parent[childNode] = node;
            }
        }
    }
  return dis;
}
 
int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> adj(n+1),adj2(n+1);

    for(ll i=0;i<m;++i){
        ll x,y,st;
        cin>>x>>y>>st;
        adj[x].push_back({y,st});
        adj2[y].push_back({x,st});
    }
    vector<ll> fromsrc=dijkstra(adj,n,1);
    vector<ll> fromdes=dijkstra(adj2,n,n);
    // for(auto &i:fromsrc){
    //     cout<<i<<" ";
    // }cout<<endl;
    // for(auto &i:fromdes){
    //     cout<<i<<" ";
    // }cout<<endl;
    ll ans=1e18;

    for(ll i=1;i<=n;++i){
        for(auto &child:adj[i]){
            ans=min(ans,fromsrc[i]+child.second/2+fromdes[child.first]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
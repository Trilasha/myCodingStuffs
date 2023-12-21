#include<bits/stdc++.h>
using namespace std;
#define ll long long


struct myhash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
        return hash1;
    }
};
 
 
vector<ll> dijkstra(vector<vector<pair<ll,ll>>> &adj,ll n,ll S){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> dis(n + 1, 1e18);
    dis[S] = 0;
    pq.push({0, S});
    while (!pq.empty()){
        ll distance = pq.top().first;
        ll node = pq.top().second;
        pq.pop();
        if(distance>dis[node]) continue;
        for (auto &i : adj[node]){
            ll childNode = i.first;
            ll edgeWeight = i.second;
            if (distance + edgeWeight < dis[childNode]){
                dis[childNode] = distance + edgeWeight;
                pq.push({dis[childNode], childNode});
            }
        }
    }
  return dis;
}
 
int main(){

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdin);
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> adj(n+3);
    unordered_map<pair<ll, ll>, ll, myhash> mp;
 
    for(ll i=0;i<m;++i){
        ll x,y,a1,a2;
        cin>>x>>y>>a1>>a2;
        adj[x].push_back({y,a1});
        adj[y].push_back({x,a1});
        if(a2>0){
           mp[{x,y}]=a2;
           mp[{y,x}]=a2;
        }
    }
 
    ll s,d;
    cin>>s>>d;
    ll ans=1e18;
    vector<ll> fromsrc=dijkstra(adj,n,s);
    vector<ll> fromdes=dijkstra(adj,n,d);
    for(ll i=1;i<=n;++i){
        for(auto &child:adj[i]){
            if(fromsrc[i]!=1e18 && fromdes[child.first]!=1e18)
            ans=min(ans,fromsrc[i]+child.second+fromdes[child.first]);
            if(mp.count({i,child.first})){
                ans=min(ans,fromsrc[i]+mp[{i,child.first}]+fromdes[child.first]);
            }
        }
    }
    if(s==d)ans=0;
    cout<<((ans==1e18)?-1:ans)<<endl;
    return 0;
}
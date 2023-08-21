#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long 

vector<ll> dijkstra(vector<vector<pair<int,int>>> &adj,int n,int S){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> dis(n + 1, 1e18);
    vector<ll> parent(n + 1);
 
    for (ll i = 1; i <= n; ++i)
        parent[i] = i;
    dis[S] = 0;
    pq.push({0, 1});
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
                parent[childNode] = node;
            }
        }
    }
  return dis;
}
 
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;++i){
        ll x,y,z;
        cin>>x>>y>>z;
        adj[x].pb({y,z});
        adj[y].pb({x,z});
    }
    map<int,int> mp;
   for(int i=0;i<k;++i){
        ll x,y;
        cin>>x>>y;
        mp[x]=y;
    }
    vector<ll> fromN=dijkstra(adj,n,n);
    vector<int> cost(n+1,-1);
    priority_queue<pair<int,int>> pq;
    for(int i=1;i<=n;++i){
        if(mp.count(i)){
            if(mp[i]-fromN[i]>0){
                pq.push({mp[i]-fromN[i],i});
                cost[i]=mp[i]-fromN[i];
            }
        }
    }

    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int sat=it.first;
        int node=it.second;
        if(cost[node]>sat) continue;
        for(auto &i:adj[node]){
            int cnode=i.first;
            int wt=i.second;
            if(sat-wt>cost[cnode]){
                cost[cnode]=sat-wt;
                pq.push({cost[cnode],cnode});
            }
        }
    }
    int cnt=0;
    for(int i=1;i<n;++i){
        if(cost[i]>=1) cnt++;
    }
    cout<<cnt<<endl;

    return 0;
}
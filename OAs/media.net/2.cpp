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

        //trying to add the set erase functionality somehow (though tc remains the same for both pq and set)
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
    int A,m;
    cin>>A>>m;
    vector<int> price(A);
    for(int i=0;i<A;++i){
        cin>>price[i];
    }
    vector<vector<pair<int,int>>> adj(A+3);
    for(int i=0;i<m;++i){
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].pb({y,z});
        adj[y].pb({x,z});
    }
    int D;
    cin>>D;
    for(int i=1;i<=A;++i){
       for(int j=0;j<adj[i].size();++j){
         adj[i][j].second=(1+D)*(adj[i][j].second);
       }
    }
    int dummy=A+1;
    for(int i=1;i<=A;++i){
        adj[i].pb({dummy,price[i]});
        adj[dummy].pb({i,price[i]});
    }
    vector<ll> distance=dijkstra(adj,A+1,dummy);
    vector<int> ans;
    for(int i=1;i<=A;++i){
        ans.pb(distance[i]);
    }
    for(auto &i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
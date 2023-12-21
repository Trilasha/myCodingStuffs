/* Trilasha Mazumder */


#include <bits/stdc++.h>
using namespace std;
           
#define ll                    long long
#define ld                    long double
#define pb                    push_back
#define lb                    lower_bound
#define ub                    upper_bound
#define ff                    first
#define ss                    second
#define maxpq                 priority_queue <ll> pq;
#define minpq                 priority_queue <ll, vector<ll>, greater<ll> > pq; 
#define inpv(v)               for(auto &x: v) cin>>x;
#define fr(i,n)               for (ll i=0;i<n;++i)
#define all(str)              str.begin(), str.end()
#define pll                   pair<ll,ll>
#define printv(v)             for(auto &i: v){cout << i << " ";} cout << endl;
#define printmap(mp)          for(auto &i: mp){cout << i.first << " "<<i.second<<endl;}
#define printset(st)          for(auto &i: st){cout << i << " ";} cout << endl;
#define line                  cout<<"----------------------------------------"<<endl;
#define arrow                 cout<<"--->";
#define debugmap(mp)          for(auto &i: mp){cout << i.ff << "-->" << i.ss <<endl;} cout << endl;
#define debugset(st)          for(auto &i: st){cout << i << " ";} cout << endl;
#define fast_io               ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sp(x)                 fixed<<setprecision(x)
#define PI                    3.141592653589793238
#define bpl(n)                __builtin_popcountll(n);
#define md                    998244353
#define modval                1000000007
//#define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- */



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

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> adj(n+3);
    map<pair<ll, ll>, ll> mp;
 
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
}


int main(){

fast_io;

ll q=1;
// cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}
 
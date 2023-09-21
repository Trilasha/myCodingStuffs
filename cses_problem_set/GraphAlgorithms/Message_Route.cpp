/* ...  risen_ash  ... */

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
// define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- */


vector<ll> dijkstra(vector<vector<pair<ll,ll>>> &adj,int n)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> dis(n + 1, 1e18);
    vector<ll> parent(n + 1);
 
    for (ll i = 1; i <= n; ++i)
        parent[i] = i;
 
    dis[1] = 0;
    pq.push({0, 1});
    // vector<int> vis(n+1);
 
    while (!pq.empty())
    {
        ll distance = pq.top().first;
        ll node = pq.top().second;
        pq.pop();
        // if(vis[node])continue;
        // vis[node]=1;
 
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
 
    if (dis[n] == 1e18)
        return {-1};
 
    vector<ll> ans;
    ll tNode = n;
 
    ans.push_back(tNode);
    while (parent[tNode] != tNode)
    {
        ans.push_back(parent[tNode]);
        tNode = parent[tNode];
    }
 
    reverse(ans.begin(), ans.end());
    return ans;
}
 
void solve(){
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    while (m--){
        ll a, b;
        cin >> a >> b;
        adj[a].pb({b, 1});
        adj[b].pb({a, 1});
    }
    vector<ll> path=dijkstra(adj,n);
    if(path[0]==-1){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    cout<<path.size()<<endl;
    printv(path);
}
 





int main(){

fast_io;

ll q=1;
//cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}











/*--------------------------------------------------------------------------------------------------------- 
   reference for sequence(NT) --> oeis.org
   log2(x)
   set.lower_bound(x)
   for mod division --> a/b use a*inverse(b) (don't divide simply)
   set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
   gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
   --------------------------------------------------------------------------------------------------------- */
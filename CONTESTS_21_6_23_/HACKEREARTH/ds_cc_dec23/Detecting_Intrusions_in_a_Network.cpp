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





struct LCA{
    vector<vector<ll>> up;
    vector<ll> tin, tout, distance;
    ll timer;
    vector<ll>store;
    LCA(ll n) {
        timer = 0;
        tin.resize(n);
        tout.resize(n);
        up.assign(n, vector<ll>(21, -1));
        distance.assign(n, 0);
        store.assign(n,0);
    }
    void dfs(ll v, ll p, vector<vector<ll>> &adj, ll dis,ll val) {
        distance[v]=dis;
        tin[v] = ++timer;
        up[v][0] = p;
        for (ll i = 1; i < 21; i++)
            up[v][i] = up[up[v][i - 1]][i - 1];

        store[v]=val;
        for (ll u : adj[v]) {
            if (u != p)
                dfs(u, v, adj, dis+1,val^(u+1));
        }
        tout[v] = ++timer;
    }
    bool is_ancestor(ll u, ll v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    ll lca(ll u, ll v) {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (ll i = 20; i >= 0; i--) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }
    ll dist(ll u, ll v) {
        int w = lca(u, v);
        return abs(distance[u] + distance[v] - 2*distance[w]);
    }
};
 

void solve(){
   ll n;
   cin>>n;
   vector<vector<ll>> adj(n);
   fr(i,n-1){
        ll x,y;
        cin>>x>>y;
        x--;y--;
        adj[x].pb(y);
        adj[y].pb(x);
   }
   LCA tree(n);
   tree.dfs(0,0,adj,0,1);
   ll q;
   cin>>q;
   while(q--){
        ll a,b,k;
        cin>>a>>b>>k;
        a--,b--;
        ll get_lca=tree.lca(a,b);
        //cout<<tree.store[a]<<" "<<tree.store[b]<<" "<<tree.store[get_lca]<<endl;
        ll xr=tree.store[a]^tree.store[b]^(get_lca+1);
        //cout<<xr<<endl;
        cout<<((xr<=k)?"SECURE":"ALERT")<<endl;
   }
}


int main(){

fast_io;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

ll q=1;
// cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}


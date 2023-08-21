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
#define sp(x)                 fixed<<setprecision(x)
#define md                    998244353
#define modval                1000000007
#define PI                    3.141592653589793238
#define bpl(n)                __builtin_popcountll(n);
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
// define endl                " \n"



ll LOG;
vector<ll> depth(300010),parent;
vector<vector<ll>> up(24,vector<ll>(300010));
vector<vector<pll>> adj;
map<ll,multiset<ll>> mp;
 
 
void dfs(ll u, ll p, ll l,ll value=1e10) {
    up[0][u] = p;
    depth[u] = l;
    mp[u].insert(value);
	
	for (auto &v: adj[u]) 
		if(v.ff != p) 
		dfs(v, u, l+1,v.ss);
}
 
void precal(ll n){
    LOG=0;
    while((1<<LOG)<=n){
        LOG++;
    }
    dfs(0, 0, 0);
	for (ll i = 1; i<=LOG ; ++i){ 
        for (ll j = 0; j < n ; ++j)
        up[i][j] = up[i-1][up[i-1][j]];
    }
 
}
 
 
ll get_lca(ll a,ll b){
    if(depth[a]<depth[b]){
        swap(a,b);
    }
 
    ll k=depth[a]-depth[b];
    for(ll i=LOG-1;i>=0;--i){
        if(k&(1<<i)){
            a=up[i][a];
        }
    }
    if(a==b) {
		return a;
	}
    
    for(ll i=LOG-1;i>=0;--i){
        if(up[i][a]!=up[i][b]){
            a=up[i][a];
            b=up[i][b];
        }
    }
 
    return up[0][a];
}
 
void solve(){
    ll n,m;
    cin>>n>>m;
    adj.resize(n+1);
  
    fr(i,m){
        ll x,y,wt;
        cin>>x>>y>>wt;
        x--;y--;
        adj[x].pb({y,wt});
        adj[y].pb({x,wt});
    }
    precal(n); 
    ll q;
    cin>>q;
    for(ll i=0;i<q;++i){
        ll x,y;
        cin>>x>>y;
        x--;y--;
        ll lca=get_lca(x,y);
        // cout<<depth[x]+depth[y]-2*depth[lca]<<endl;
        
        ll mn=
    }
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
 
 
 
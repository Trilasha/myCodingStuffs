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


//BINARY-LIFTING
//since the root is not always 1 (~0) so this code wouldn't work since depth is calculated wrt node 1 as root
//instead we will use dfs to implment binary lifting

ll LOG;
vector<ll> depth(200005),parent;
vector<vector<ll>> up(24,vector<ll>(200005));
vector<vector<ll>> adj;


void dfs(ll u, ll p, ll l) {
    up[0][u] = p;
    depth[u] = l;
	
	for (auto &v: adj[u]) 
		if(v != p) 
		dfs(v, u, l+1);
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
    ll n,q;
    cin>>n>>q;
    parent.resize(n+1);
    adj.resize(n+1);
  
    fr(i,n-1){
        ll x,y;
        cin>>x>>y;
        x--;y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    precal(n); 

    for(ll i=0;i<q;++i){
        ll x,y;
        cin>>x>>y;
        x--;y--;
        ll lca=get_lca(x,y);
        cout<<depth[x]+depth[y]-2*depth[lca]<<endl;
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










/*--------------------------------------------------------------------------------------------------------- 
   reference for sequence(NT) --> oeis.org
   LOG2(x)
   set.lower_bound(x)
   for mod division --> a/b use a*inverse(b) (don't divide simply)
   set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
   gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
   --------------------------------------------------------------------------------------------------------- */
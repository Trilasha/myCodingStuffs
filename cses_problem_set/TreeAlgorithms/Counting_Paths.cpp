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




//applying the concept of prefix-sum on trees to count the number of paths between two nodes in a tree

ll LOG;
vector<ll> depth(200005),parent(200005),prefix(200005);
vector<vector<ll>> up(24,vector<ll>(200005));
vector<vector<ll>> adj(200005);


void dfs(ll u, ll p, ll l) {
    up[0][u] = p;
    depth[u] = l;
    parent[u]=p;

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


void dfs_prefix(ll node,ll par){
    for(auto &child: adj[node]){
        if(child!=par){
            dfs_prefix(child,node);
            prefix[node]+=prefix[child];
        }
    }
}


void solve(){
    ll n,paths;
    cin>>n>>paths;
    fr(i,n-1){
        ll x,y;
        cin>>x>>y;
        x--;y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    precal(n);

    fr(i,paths){
        ll x,y;
        cin>>x>>y;
        x--;y--;
        prefix[x]++;
        prefix[y]++;
        ll lca=get_lca(x,y);
        prefix[lca]--;
        if(parent[lca]!=lca){
            prefix[parent[lca]]--;
        }
    }

    dfs_prefix(0,-1);
    for(ll i=0;i<n;++i){
        cout<<prefix[i]<<" ";
    }
    cout<<endl;
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
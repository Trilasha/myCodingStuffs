/*
    Trilasha Mazumder
*/

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
// insead of bpow use shift operators when b=2 to avoid tle 
// do not perform more than one optimal choice/ops in a single step/loop otherwise break your head with WA



 
vector<ll> dis;
struct centroidDecompose{
    ll n;
    vector<vector<ll>> adj;
    vector<ll> sz,lvl,cPar;
    vector<vector<ll>> up;
    vector<ll> tin, tout, distance;
    ll timer;

    centroidDecompose(ll n){
        this->n=n;
        sz.resize(n+1);
        lvl.resize(n+1);
        cPar.resize(n+1);
        timer = 0;
        tin.resize(n+1);
        tout.resize(n+1);
        up.assign(n+1, vector<ll>(21, -1));
        distance.assign(n+1, 0);
    }
    ll getSize(ll v, ll p){
        sz[v]=1;
        for(auto u: adj[v]){
            if(u!=p && !lvl[u]){
                sz[v]+=getSize(u,v);
            }
        }
        return sz[v];
    }   
    ll centroid(ll v, ll p, ll n){
        for(auto u: adj[v]){
            if(u!=p && !lvl[u] && sz[u]>n/2){
                return centroid(u,v,n);
            }
        }
        return v;
    }
    ll decompose(ll v, ll l){
    //    sz.assign(n+1,0LL);
       ll cent=centroid(v,-1,getSize(v,-1));
       lvl[cent]=l;
       for(auto u: adj[cent]){
           if(!lvl[u]){
               ll subCent=decompose(u,l+1);
               cPar[subCent]=cent;
           }
       }
       return cent;
    }
    void dfs(ll v, ll p, ll dis) {
        distance[v]=dis;
        tin[v] = ++timer;
        up[v][0] = p;
        for (ll i = 1; i < 21; i++)
            up[v][i] = up[up[v][i - 1]][i - 1];
 
        for (ll u : adj[v]) {
            if (u != p)
                dfs(u, v, dis+1);
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
    ll findDist(ll u, ll v) {
        ll w = lca(u, v);
        return abs(distance[u] + distance[v] - 2*distance[w]);
    }
};

void paint(ll node, vector<ll> &cdpar, centroidDecompose &cd){
    ll par=node;
    while(par){
        dis[par]=min(dis[par],cd.findDist(node,par));
        par=cdpar[par];
    }
}

ll query(ll node, vector<ll> &cdpar, centroidDecompose &cd){
    ll par=node;
    ll ans=1e17;
    while(par){
        ans=min(ans,dis[par]+cd.findDist(node,par));
        par=cdpar[par];
    }
    return ans;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1);
    fr(i,n-1){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    centroidDecompose cd(n);
    cd.adj=adj;
    cd.decompose(1,1);
    cd.dfs(1, 1, 0);
    vector<ll> cdpar=cd.cPar;
    dis.assign(n+1,1e17);

    paint(1,cdpar,cd);
    fr(i,m){
        ll type,node;
        cin>>type>>node;
        if(type==1){
            paint(node,cdpar,cd);
        }else{
            cout<<query(node,cdpar,cd)<<endl;
        }
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


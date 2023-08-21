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




//to find mst --> kruskal's algorithm
//tc -> ElogE (E --> the vector containing all the edges)
//dsu is used


class DSU{
    vector<ll> par,size;
    
public:
    ll tot_components;
    DSU(ll n)
    {
        size.resize(n+1,1);
        par.resize(n+1);
        for(ll i=1;i<=n;++i)
        par[i]=i;
 
        tot_components=n;
    }
 
 
    ll findPar(ll node)
    {
        if (node==par[node])
        return node;
        return par[node]=findPar(par[node]);
    }
 
    ll getsize(ll node){
        return size[findPar(node)];
    }
 
    void unite(ll u,ll v)
    {
        ll ult_u=findPar(u);
        ll ult_v=findPar(v);
        if(ult_u==ult_v)return;
        if(size[ult_u]<size[ult_v])
        {
            size[ult_v]+=size[ult_u];
            par[ult_u]=ult_v;
        }
        else
        {
            size[ult_u]+=size[ult_v];
            par[ult_v]=ult_u;
        }
        tot_components--;
    }

    bool same(ll u,ll v){
        if(findPar(u)==findPar(v))return true;
        return false;
    }
};
 
 

void solve(){
    ll n,m;
    cin>>n>>m;
    DSU ds(n);
    vector<pair<ll,pll>> edges;
    for(ll i=0;i<m;++i){
        ll u,v,w;
        cin>>u>>v>>w;
        edges.pb({w,{u,v}});
    }
    sort(all(edges));
    ll ans=0;
    fr(i,m){
        ll u=edges[i].ss.ff;
        ll v=edges[i].ss.ss;
        if(!ds.same(u,v)){
            ds.unite(u,v);
            ans+=edges[i].ff;
        }
    }

    if(ds.tot_components==1)cout<<ans<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
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






/*----------------------------------------------------------------------------------------------------------- */
// clear adj and visited vector declared globally after each test case 
// if input newly taken then use 'resize' or else 'assign' (for dp and graphs)
//    BINARY SEARCH ~ 2-PNTS ~ DP 
//    reference for sequence(NT) --> oeis.org
//    log2(x)
//    set.lower_bound(x)
//    for mod division --> a/b use a*inverse(b) (don't divide simply)
//    set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
//    gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
//    if nlogn approach gives tle, go for O(n) don't sit idle (for lb/ub replace set with vector)
//    if 100% sure that chk func is correct then try changing the values of lo/hi in the main func (hit and trial)
/*----------------------------------------------------------------------------------------------------------- */



   

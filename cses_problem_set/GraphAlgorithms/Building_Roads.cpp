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





vector<vector<ll>> adj(200005);

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
};
 
 
void solve(){
    ll n,r;
    cin>>n>>r;
    DSU ds(n);
    for(ll i=0;i<r;++i)
    {
        ll u,v;
        cin>>u>>v;
        ds.unite(u,v);
    }
    cout<<ds.tot_components-1<<endl;
    set<ll> st;
    for(ll i=1;i<=n;++i){
        st.insert(ds.findPar(i));
    }
    vector<ll> ans(all(st));
    for(ll i=0;i<ans.size()-1;++i){
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
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
   log2(x)
   set.lower_bound(x)
   for mod division --> a/b use a*inverse(b) (don't divide simply)
   set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
   gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
   --------------------------------------------------------------------------------------------------------- */
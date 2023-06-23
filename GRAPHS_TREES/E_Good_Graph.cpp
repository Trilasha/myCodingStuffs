#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp> 


using namespace std;
//using namespace __gnu_pbds;
//typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; 

           
#define ll                    long long
#define ld                    long double
#define pb                    push_back
#define popb                  pop_back
#define lb                    lower_bound
#define ub                    upper_bound
#define ff                    first
#define ss                    second
#define maxpq                 priority_queue <ll> pq;
#define minpq                 priority_queue <ll, vector<ll>, greater<ll> > pq; 
#define sp(x)                 fixed<<setprecision(x)
/// ---------------------------------------------------------------------------------------------------------- ///
#define md                    998244353
#define modval                1000000007
#define PI                    3.141592653589793238
#define bpl(n)                __builtin_popcountll(n);
/// ---------------------------------------------------------------------------------------------------------- ///
#define inp(n)                ll n;cin>>n;
#define inpv(v)               for(auto &x: v) cin>>x;
#define make(arr,n)           ll arr[n]; fr(i,n) cin>>arr[i];
/// ---------------------------------------------------------------------------------------------------------- ///
#define fr(i,n)               for (ll i=0;i<n;++i)
#define frs(i,k,n)            for(ll i=k;i<n;++i)
#define all(str)              str.begin(), str.end()
#define pll                   pair<ll,ll>
/// --------------------------------------------------------------------------------------------------------- ///
#define printv(v)             for(auto &i: v){cout << i << " ";} cout << endl;
#define printmap(mp)          for(auto &i: mp){cout << i.first << " "<<i.second<<endl;}
#define printset(st)          for(auto &i: st){cout << i << " ";} cout << endl;
#define line                  cout<<"----------------------------------------"<<endl;
#define arrow                 cout<<"--->";
#define debugmap(mp)             for(auto &i: mp){cout << i.ff << "-->" << i.ss <<endl;} cout << endl;
#define debugset(st)             for(auto &i: st){cout << i << " ";} cout << endl;
#define fast_io               ios_base::sync_with_stdio(false);cin.tie(NULL);
//#define endl                  " \n"
/// --------------------------------------------------------------------------------------------------------- ///

/// --------------------------------------------------------------------------------------------------------- ///
//reference for sequence(NT) --> oeis.org
//log2(x)
//give separate condition checks for smaller values of n(like n<=2)
//never use = sign in comparator functions
//the real challenge of bs --> selection of lo and hi
//set.lower_bound(x)
//for mod division --> a/b use a*inverse(b) (don't divide simply)
//set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
//gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
/// --------------------------------------------------------------------------------------------------------- ///




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
    ll n,e;
    cin>>n>>e;
    DSU ds(n);
    fr(i,e){
        ll x,y;
        cin>>x>>y;
        ds.unite(x,y);
    }

    ll k;
    cin>>k;
    map<pll,ll> mp;
    fr(i,k){
        ll x,y;
        cin>>x>>y;
        ll pp1=ds.findPar(x);
        ll pp2=ds.findPar(y);
        mp[{pp1,pp2}]++;
        mp[{pp2,pp1}]++;

    }

    ll qqq;
    cin>>qqq;
    fr(i,qqq){
        ll x,y;
        cin>>x>>y;
        ll ok=0;
        ll par1=ds.findPar(x);
        ll par2=ds.findPar(y);

        cout<<((mp[{par1,par2}])?"No":"Yes")<<endl;
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
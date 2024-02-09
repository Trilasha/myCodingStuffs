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





class DSU{
    vector<ll> par,size;
public:
    ll tot_components;
    DSU(ll n){
        size.resize(n+1,1);
        par.resize(n+1);
        for(ll i=1;i<=n;++i)
        par[i]=i;
        tot_components=n;
    }
    ll findPar(ll node){
        if (node==par[node])
        return node;
        return par[node]=findPar(par[node]);
    }
    ll getsize(ll node){
        return size[findPar(node)];
    }
    void unite(ll u,ll v){
        ll ult_u=findPar(u);
        ll ult_v=findPar(v);
        if(ult_u==ult_v)return;
        if(size[ult_u]<size[ult_v]){
            size[ult_v]+=size[ult_u];
            par[ult_u]=ult_v;
        }else{
            size[ult_u]+=size[ult_v];
            par[ult_v]=ult_u;
        }
        tot_components--;
    }
};
 

void solve(){
    ll n,m;
    cin>>n>>m;
    DSU dsu(n); 
    map<ll,ll> mp,par;
    fr(i,m){
        ll u,v;
        cin>>u>>v;
        if(u==v)continue;
        dsu.unite(u,v);
        mp[u]++;
        mp[v]++;
    }
    for(ll i=1;i<=n;++i){
        ll x=dsu.findPar(i);
        par[x]+=mp[i];
    }
    ll ans=0;
    for(auto &i:par){
        ll sz=dsu.getsize(i.ff); 
        ll cnt=i.ss/2;
        if(cnt<sz){
            ans+=cnt;
        }else{
            ans+=sz+1;
        }
    }
    cout<<ans<<endl;
}


int main(){

fast_io;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

ll q=1;
cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}


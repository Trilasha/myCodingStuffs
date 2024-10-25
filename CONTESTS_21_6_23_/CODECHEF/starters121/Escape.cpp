/*
    When talent doesn't work hard then hardwork beats talent...
    ...hardwork always pays off
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
vector<pll> vp={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};

void solve(){
    ll n,m;
    cin>>n>>m;
    map<ll,pll> mp;
    map<pll,ll> st;
    ll cnt=0;
    fr(i,m){
        ll a,b;
        cin>>a>>b;
        st[{a,b}]=++cnt;
        mp[cnt]={a,b};
    }
    DSU ds(cnt);
    for(ll i=1;i<=cnt;++i){
        ll x=mp[i].ff;
        ll y=mp[i].ss;
        for(ll j=0;j<8;++j){
            ll xx=x+vp[j].ff;
            ll yy=y+vp[j].ss;
            if(st.count({xx,yy})){
                ds.unite(i,st[{xx,yy}]);
            }
        }
    }
    map<ll,pair<pll,pll>> par;
    //minx maxx miny maxy
    for(ll i=1;i<=cnt;++i){
        ll x=ds.findPar(i);
        if(!par.count(x)){
            par[x]={{mp[i].ff,mp[i].ff},{mp[i].ss,mp[i].ss}};
        }else{
            par[x].ff.ff=min(par[x].ff.ff,mp[i].ff);
            par[x].ff.ss=max(par[x].ff.ss,mp[i].ff);
            par[x].ss.ff=min(par[x].ss.ff,mp[i].ss);
            par[x].ss.ss=max(par[x].ss.ss,mp[i].ss);
        }
    }
    ll ok=0;
    for(auto &i:par){
        ll minx=i.ss.ff.ff;
        ll maxx=i.ss.ff.ss;
        ll miny=i.ss.ss.ff;
        ll maxy=i.ss.ss.ss;
        if((minx==1 && maxy==n) || (miny==1 && maxy==n) || (miny==1 && minx==1) || (maxx==n && maxy==n)){
            ok=1;
        }
    }
    cout<<((ok)?"NO":"YES")<<endl;

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


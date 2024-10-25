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
    vector<pll> mp;
    mp.pb({0,0});
    map<pll,ll> st;
    ll cnt=0;
    fr(i,m){
        ll a,b;
        cin>>a>>b;
        st[{a,b}]=++cnt;
        mp.pb({a,b});
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
    map<ll,array<ll,4>> par;
    //minx maxx miny maxy
    for(ll i=1;i<=cnt;++i){
        ll x=ds.findPar(i);
        ll xx=mp[i].ff;
        ll yy=mp[i].ss;
        if(!par.count(x)){
            par[x]={xx,xx,yy,yy};
        }else{
            par[x][0]=min(par[x][0],xx);
            par[x][1]=max(par[x][1],xx);
            par[x][2]=min(par[x][2],yy);
            par[x][3]=max(par[x][3],yy);
        }
    }
    ll ok=0;
    for(auto &i:par){
        ll minx=i.ss[0];
        ll maxx=i.ss[1];
        ll miny=i.ss[2];
        ll maxy=i.ss[3];
        if((minx==1 && miny==1) || (miny==1 && maxy==n) || (maxx==n && maxy==n) || (minx==1 && maxx==n)){
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

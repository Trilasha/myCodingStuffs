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






struct segtree{
    vector<ll> v;ll id=0,sz;//id for initialization
    segtree(ll _n){sz=1;while(sz<_n){sz<<=1;}v.assign(2*sz,id);}
    ll func(ll x,ll y){ return x+y;}
    void pull(ll x){ v[x]=func(v[2*x+1],v[2*x+2]);}
    void update(ll i, ll val, ll x, ll lx, ll rx){ // 0-based indexing 
        if(rx-lx==1){ v[x]=val; return;}
        ll m=(lx+rx)/2;
        if(i<m){update(i,val,2*x+1,lx,m);}
        else{update(i,val,2*x+2,m,rx);}
        pull(x);
    }
    void update(ll i, ll val){ update(i,val,0,0,sz);}
    ll query(ll l,ll r,ll x,ll lx,ll rx){ // [l,r) l->INCLUSIVE/ r->EXCLUSIVE
        if(lx>=r || l>=rx) return id;
        if(lx>=l && rx<=r) return v[x];
        ll m=(lx+rx)/2;
        ll s1=query(l,r,2*x+1,lx,m);
        ll s2=query(l,r,2*x+2,m,rx);
        return func(s1,s2);
    }
    ll query(ll l,ll r){ return query(l,r,0,0,sz);}
};

void solve(){
    ll n,q;
    cin>>n>>q;
    vector<ll> v(n);
    inpv(v);
    vector<pair<pll,ll>> vp;
    fr(i,q){
        ll x,y;
        cin>>x>>y;
        vp.pb({{x,y},i});
    }
    sort(all(vp));
    vector<ll> ans(q);
    ll mx=*max_element(all(v));
    vector<ll> cnt(mx+1);
    segtree st(mx+1);
    ll last=-1;
    for(ll i=0;i<q;++i){
        ll l=vp[i].ff.ff;
        ll r=vp[i].ff.ss;
        ll ind=vp[i].ss;
        for(ll j=last+1;j<=l;++j){
            cnt[v[j]]++;
            st.update(v[j],cnt[v[j]]*v[j]);
        }
        last=l;
        ans[ind]=st.query(v[r]+1,mx+1);
    }
    printv(ans);
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




void dk(){
     ll n,q;
     cin>>n>>q;
     vl a;
     vector<pll>v;
     rep(i,0,n){
          ll x;
          cin>>x;
          a.pb(x);
          v.pb({x,i});
     }
     vector<array<ll,3>>query;
     rep(i,0,q){
          ll l,r;
          cin>>l>>r;
          query.pb({a[r],l,i});
     }

     sort(all(v),greater<pll>());
     sort(all(query),greater<array<ll,3>>());
     bit<ll>bit(n+1);
     vector<ll>ans(q);

     for(int i=0,j=0;i<q;i++){ 
          ll l=query[i][1],val=query[i][0],ind=query[i][2];
          while(j<n and v[j].first>val){
               bit.update(v[j].second,v[j].first);
               j++;
          }
          ans[ind]=bit.query(l+1);
     }
     for(auto i:ans){
          cout<<i<<" "; 
     }
     cout<<endl;
}
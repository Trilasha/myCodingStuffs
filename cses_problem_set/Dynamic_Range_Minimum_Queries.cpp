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
    vector<ll> v;ll id=INT_MAX,sz;//id for initialization
    segtree(ll _n){sz=1;while(sz<_n){sz<<=1;}v.assign(2*sz,id);}
    ll func(ll x,ll y){ return min(x,y);}
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
   segtree st(n);
   fr(i,n){
    st.update(i,v[i]);
   }
   while(q--){
    ll t,a,b;
    cin>>t>>a>>b;
    if(t==1){
        v[a-1]=b;
        st.update(a-1,b);
    }else{
        cout<<st.query(a-1,b)<<endl;
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


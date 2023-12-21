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
    
    ll size;
    vector<ll> sums;

    void init(ll n){
        size=1;
        while(size<n) size*=2;
        sums.assign(2*size,INT_MAX);
    }
    void build(vector<ll> &v, ll x, ll lx, ll rx){
        if(rx-lx==1){
            if(lx<(ll)v.size()){
                sums[x]=v[lx];
            }
            return;
        }
        ll m=(lx+rx)/2;
        build(v,2*x+1,lx,m);
        build(v,2*x+2,m,rx);
        sums[x]=min(sums[2*x+1],sums[2*x+2]);
    }
    void build(vector<ll> &v){
        build(v,0,0,size);
    }
    void set(ll i, ll v, ll x, ll lx, ll rx){
        if(rx-lx==1){
            sums[x]=v;
            return;
        }
        ll m=(lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }
        else{
            set(i,v,2*x+2,m,rx);
        }
        sums[x]=min(sums[2*x+1],sums[2*x+2]);
    }
    void set(ll index,ll val){
        set(index,val,0,0,size);
    }
    ll miny(ll l,ll r,ll x,ll lx,ll rx){
        if(lx>=r || l>=rx) return INT_MAX;
        if(lx>=l && rx<=r) return sums[x];
        ll m=(lx+rx)/2;
        ll s1=miny(l,r,2*x+1,lx,m);
        ll s2=miny(l,r,2*x+2,m,rx);
        return min(s1,s2);
    }
    ll miny(ll l,ll r){
        return miny(l,r,0,0,size);
    }
};



void solve(){
    ll n,q;
    cin>>n>>q;
    vector<ll> v(n);
    inpv(v);

    segtree st;
    st.init(n);
    st.build(v);

    while(q--){
        ll type;
        cin>>type;
        if(type==1){
            ll x,y;
            cin>>x>>y;
            st.set(x,y);
        }
        else{
            ll l,r;
            cin>>l>>r;
            cout<<st.miny(l,r)<<endl;
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


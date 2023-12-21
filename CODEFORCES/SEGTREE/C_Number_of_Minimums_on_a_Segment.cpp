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
    vector<pll> sums;

    void init(ll n){
        size=1;
        while(size<n) size*=2;
        sums.assign(2*size,{INT_MAX,0LL});
    }
    void build(vector<ll> &v, ll x, ll lx, ll rx){
        if(rx-lx==1){
            if(lx<(ll)v.size()){
                sums[x]={v[lx],1LL};
            }
            return;
        }
        ll m=(lx+rx)/2;
        build(v,2*x+1,lx,m);
        build(v,2*x+2,m,rx);
        pll p1=sums[2*x+1];
        pll p2=sums[2*x+2];
        if(p1.first<p2.first){
            sums[x]=p1;
        }
        else if(p1.first>p2.first){
            sums[x]=p2;
        }
        else{
            sums[x]={p1.first,p1.second+p2.second};
        }
    }
    void build(vector<ll> &v){
        build(v,0,0,size);
    }
    void set(ll i, ll v, ll x, ll lx, ll rx){
        if(rx-lx==1){
            sums[x]={v,1};
            return;
        }
        ll m=(lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }
        else{
            set(i,v,2*x+2,m,rx);
        }
        pll p1=sums[2*x+1];
        pll p2=sums[2*x+2];
        if(p1.first<p2.first){
            sums[x]=p1;
        }
        else if(p1.first>p2.first){
            sums[x]=p2;
        }
        else{
            sums[x]={p1.first,p1.second+p2.second};
        }
    }
    void set(ll index,ll val){
        set(index,val,0,0,size);
    }
    pll miny(ll l,ll r,ll x,ll lx,ll rx){
        if(lx>=r || l>=rx) return {INT_MAX,0LL};
        if(lx>=l && rx<=r) return sums[x];
        ll m=(lx+rx)/2;
        pll s1=miny(l,r,2*x+1,lx,m);
        pll s2=miny(l,r,2*x+2,m,rx);
        if(s1.first<s2.first){
            return s1;
        }
        else if(s1.first>s2.first){
            return s2;
        }
        else{
            return {s1.first,s1.second+s2.second};
        }
    }
    pll miny(ll l,ll r){
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
            pll p1=st.miny(l,r);
            cout<<p1.first<<" "<<p1.second<<endl;
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


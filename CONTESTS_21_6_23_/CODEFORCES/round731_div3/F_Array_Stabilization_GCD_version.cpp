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






/*
16 24 / 24 10/ 10 5/ 5 16
  8 2 5 1 
8 2/ 2 5/ 5 1/ 1 8
  2 1 1 1
2 1/1 1/1 1/1 1
  1 1 1 1 

4 6 4
4 6/ 6 4/ 4 4 -> 2 2 4
2 2/2 4/4 2   -> 2 2 2 
*/

struct segtree{ 
    ll size;
    vector<ll> g;
    void init(ll n){
        size=1;
        while(size<n) size*=2;
        g.assign(2*size,0LL);
    }
    void set(ll i, ll v, ll x, ll lx, ll rx){
        if(rx-lx==1){
            g[x]=v;
            return;
        }
        ll m=(lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }
        else{
            set(i,v,2*x+2,m,rx);
        }
        g[x]=__gcd(g[2*x+1],g[2*x+2]);
    }
    void set(ll i, ll v){
        set(i,v,0,0,size);
    }
    ll find_gcd(ll l, ll r,ll x,ll lx, ll rx){
        if(lx>=r || l>=rx) return 0;
        if(lx>=l && rx<=r) return g[x];
        ll m=(lx+rx)/2;
        ll g1=find_gcd(l,r,2*x+1,lx,m);
        ll g2=find_gcd(l,r,2*x+2,m,rx);
        return __gcd(g1,g2);
    }
    ll find_gcd(ll l,ll r){
        return find_gcd(l,r,0,0,size);
    }
};
void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    inpv(v);
    vector<ll> pref(n);
    set<ll> stt1,stt0;

    for(ll i=0;i<n;++i){
        stt0.insert(v[i]);
        pref[i]=__gcd(v[i],v[(i+1)%n]);
        stt1.insert(pref[i]);
    }
    if(stt0.size()==1){
        cout<<0<<endl;
        return;
    }
    if(stt1.size()==1){
        cout<<1<<endl;
        return;
    }
    //printv(pref);
    segtree st;
    st.init(n);
    for(ll i=0;i<n;++i){
        st.set(i,pref[i]);
    }

    auto check=[&](ll mid)->bool{
        set<ll> s;
        if(mid<=1) return 0;
        mid--;
        for(ll i=0;i<n;++i){           
           ll after=0,before=0;
           after=st.find_gcd(i,min(i+mid+1,n));
           if(i+mid+1>n){
            before=st.find_gcd(0,(n-i-mid+2));
           }
        //    cout<<after<<" "<<before<<endl;
           //cout<<__gcd(after,before)<<endl;
           s.insert(__gcd(after,before));
        }
        return (s.size()==1);
    };

    ll low=0;
    ll high=n+1;
    ll ans=n-1;
    while(low<=high){
        ll mid=(low+high)/2;
        // cout<<mid<<endl;
        if(check(mid)){
            // cout<<mid<<endl;
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    // cout<<check(5)<<endl;
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


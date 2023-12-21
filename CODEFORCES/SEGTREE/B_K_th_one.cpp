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
        sums.assign(2*size,0LL);
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
        sums[x]=sums[2*x+1]+sums[2*x+2];
    }
    void set(ll i, ll v){
        set(i,v,0,0,size);
    }
    ll find_kth(ll k, ll x, ll lx, ll rx){
        if(rx-lx==1) return lx;
        ll m=(lx+rx)/2;
        ll sl=sums[2*x+1];
        if(sl>=(k+1)){
            return find_kth(k,2*x+1,lx,m);
        }
        else{
            return find_kth(k-sl,2*x+2,m,rx);
        }
    }
    ll find_kth(ll k){
        return find_kth(k,0,0,size);
    }
};
void solve(){
    ll n,q;
    cin>>n>>q;
    vector<ll> v(n);
    inpv(v);
    segtree st;
    st.init(n);
    fr(i,n){
        st.set(i,v[i]);
    }
    while(q--){
        ll a;
        cin>>a;
        if(a==1){
            ll ind;
            cin>>ind;
            v[ind]^=1;
            st.set(ind,v[ind]);
        }
        else{
            ll k;
            cin>>k;
            cout<<st.find_kth(k)<<endl;
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


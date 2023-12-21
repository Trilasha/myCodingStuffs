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
    ll func(ll x,ll y,ll ok){ return ((!ok)?x|y:x^y);} // any associative function
    void pull(ll x,ll ok){ v[x]=func(v[2*x+1],v[2*x+2],ok);}
    bool update(ll i, ll val, ll x, ll lx, ll rx){ // 0-based indexing 
        if(rx-lx==1){ v[x]=val; return 0;}
        ll m=(lx+rx)/2;
        ll ok=0;
        if(i<m){ok=update(i,val,2*x+1,lx,m);}
        else{ok=update(i,val,2*x+2,m,rx);}
        pull(x,ok);
        return !ok;
    }
    void update(ll i, ll val){ update(i,val,0,0,sz);}
};

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> v(1<<n);
    inpv(v);
    segtree st(1<<n);
    fr(i,1<<n){
        st.update(i,v[i]);
    }
    while(m--){
        ll ind,val;
        cin>>ind>>val;
        ind--;
        st.update(ind,val);
        cout<<st.v[0]<<endl;
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


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






class BIT{
    vector<ll> bit;
public:
    BIT(ll n)
    {
        bit.resize(n+1,0);
    }
    void update(ll x, ll val,ll n)
    {
        for(; x <= n; x += x&-x)
            bit[x] += val;
    }
    ll query(ll x)
    {
        ll sum = 0;
        for(; x > 0; x -= x&-x)
            sum += bit[x];
        return sum;
    }
};

void solve(){
    ll n;
    cin>>n;
    vector<pll> v;
    ll mx=0;
    for(ll i=0;i<n;++i){
        ll a,b;
        cin>>a>>b;
        v.pb({a,b});
        mx=max(mx,b);
    }
    // cout<<mx<<endl;
    sort(all(v));
    BIT bt(mx+1);
    ll ans=INT_MAX;
    for(ll i=0;i<n;++i){
        ll a=v[i].ff;
        ll b=v[i].ss;
        bt.update(a,1,mx+1);
        bt.update(b+1,-1,mx+1);
    }
    ans=INT_MAX;
    for(ll i=0;i<n;++i){
        ll qu1=bt.query(v[i].ff);
        ll qu2=bt.query(v[i].ss);
        // cout<<qu1<<" "<<qu2<<endl;
        ans=min(ans,max(max(0LL,qu1-1),max(0LL,qu2-1)));
    }
    cout<<ans<<endl;
}


int main(){

fast_io;

ll q=1;
// cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}


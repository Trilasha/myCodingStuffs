#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp> 


using namespace std;
//using namespace __gnu_pbds;
//typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; 

           
#define ll                    long long
#define ld                    long double
#define pb                    push_back
#define popb                  pop_back
#define lb                    lower_bound
#define ub                    upper_bound
#define ff                    first
#define ss                    second
#define maxpq                 priority_queue <ll> pq;
#define minpq                 priority_queue <ll, vector<ll>, greater<ll> > pq; 
#define sp(x)                 fixed<<setprecision(x)
/// ---------------------------------------------------------------------------------------------------------- ///
#define md                    998244353
#define modval                1000000007
#define PI                    3.141592653589793238
#define bpl(n)                __builtin_popcountll(n);
/// ---------------------------------------------------------------------------------------------------------- ///
#define inp(n)                ll n;cin>>n;
#define inpv(v)               for(auto &x: v) cin>>x;
#define make(arr,n)           ll arr[n]; fr(i,n) cin>>arr[i];
/// ---------------------------------------------------------------------------------------------------------- ///
#define fr(i,n)               for (ll i=0;i<n;++i)
#define frs(i,k,n)            for(ll i=k;i<n;++i)
#define all(str)              str.begin(), str.end()
#define pll                   pair<ll,ll>
/// --------------------------------------------------------------------------------------------------------- ///
#define printv(v)             for(auto &i: v){cout << i << " ";} cout << endl;
#define printmap(mp)          for(auto &i: mp){cout << i.first << " "<<i.second<<endl;}
#define printset(st)          for(auto &i: st){cout << i << " ";} cout << endl;
#define line                  cout<<"----------------------------------------"<<endl;
#define arrow                 cout<<"--->";
#define debugmap(mp)             for(auto &i: mp){cout << i.ff << "-->" << i.ss <<endl;} cout << endl;
#define debugset(st)             for(auto &i: st){cout << i << " ";} cout << endl;
#define fast_io               ios_base::sync_with_stdio(false);cin.tie(NULL);

/// --------------------------------------------------------------------------------------------------------- ///
//reference for sequence(NT) --> oeis.org
//log2(x)
//give separate condition checks for smaller values of n(like n<=2)
//never use = sign in comparator functions
//the real challenge of bs --> selection of lo and hi
//set.lower_bound(x)
//for mod division --> a/b use a*inverse(b) (don't divide simply)
/// --------------------------------------------------------------------------------------------------------- ///



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
    ll n,qq;
    cin>>n>>qq;
    vector<ll> v(n+1);
    maxpq;

    for(ll i=1;i<=n;++i){
        cin>>v[i];
        pq.push(v[i]);
    }

    sort(all(v),greater<ll>());
    ll ans=0;

    vector<pll> vp;
    map<ll,ll> cnt;

    fr(i,qq){
        ll x,y;
        cin>>x>>y;
        cnt[x]++;
        if(y!=n)
        cnt[y+1]--;
        vp.pb({x,y});
    }
    for(ll i=2;i<=n;++i)
    cnt[i]+=cnt[i-1];

    vector<pll> vp2;
    for(ll i=0;i<n;++i){
        vp2.pb({cnt[i+1],i+1});
    }

    sort(all(vp2),greater<pll>());

    vector<ll> temp(n+1);
    for(ll i=1;i<=n;++i){
        temp[vp2[i-1].ss]=pq.top();
        pq.pop();
    }

    BIT bt(n);
    for(ll i=1;i<=n;++i){
        bt.update(i,temp[i],n);
    }

    fr(i,qq){
        ll x=vp[i].ff;
        ll y=vp[i].ss;
        ll val=bt.query(y)-bt.query(x-1);
        ans+=val;
    }

    cout<<ans<<endl;
    for(ll i=1;i<=n;++i){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
    //line

}


int main(){

fast_io;

ll q=1;
cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}
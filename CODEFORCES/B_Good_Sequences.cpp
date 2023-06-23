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





vector<vector<ll>> divisors(1000001);
void pre(){
    for(ll i=2;i<=100001;i++){
        for(ll j=i;j<=100001;j+=i){
            divisors[j].pb(i);
        }
    }
}

void solve(){
    ll n;cin>>n;
    vector<ll> v(n);
    inpv(v);
    if(n==1){
        cout<<1<<endl;
        return;
    }

    vector<ll> dp(1000001,0); // dp[x] --> max length of subsequence ending at x --> max value of d[i] (x%i==0) + 1
    vector<ll> d(1000001,0); // d[i] -->max value of dp[x] where x%i==0
    for(ll i=0;i<n;++i){
        ll x=v[i];
        for(ll j=0;j<divisors[x].size();++j){
            ll div=divisors[x][j];
            dp[x]=max(dp[x],d[div]+1);
        }
        for(ll j=0;j<divisors[x].size();++j){
            ll div=divisors[x][j];
            d[div]=max(d[div],dp[x]);
        }
    }

    ll ans=1;
    for(ll i=0;i<=1000001;++i){
        ans=max(ans,d[i]);
    }
    cout<<ans<<endl;
}


int main(){

fast_io;

ll q=1;
pre();
//cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}
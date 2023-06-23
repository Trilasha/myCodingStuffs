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
//#define endl                  " \n"
/// --------------------------------------------------------------------------------------------------------- ///

/// --------------------------------------------------------------------------------------------------------- ///
//reference for sequence(NT) --> oeis.org
//log2(x)
//give separate condition checks for smaller values of n(like n<=2)
//never use = sign in comparator functions
//the real challenge of bs --> selection of lo and hi
//set.lower_bound(x)
//for mod division --> a/b use a*inverse(b) (don't divide simply)
//set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
//gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
/// --------------------------------------------------------------------------------------------------------- ///




vector<vector<ll>> v;
vector<vector<ll>> dp;
ll n;
vector<pair<ll,vector<ll>>> vp;

bool cmp(pair<ll,vector<ll>> &a,pair<ll,vector<ll>> &b){
    return a.ff>b.ff;
}


ll recur(ll ind, ll can_take){
    if(ind==n)return 0;

    if(dp[ind][can_take]!=-1)
    return dp[ind][can_take];

    ll w=vp[ind].ss[0];
    ll s=vp[ind].ss[1];
    ll val=vp[ind].ss[2];

    ll ans=0;

    //pick
    if(w<=can_take){
        ans = val+recur(ind+1,min(can_take-w,s));
    }
    //not pick
    return dp[ind][can_take]=max(ans,recur(ind+1,can_take));
}

void solve(){
    cin>>n;
    v.resize(n+1);
    ll mx=0;
    fr(i,n){
        ll w,s,v;
        cin>>w>>s>>v;
        mx=max(mx,s);
        vector<ll> temp={w,s,v};
        vp.pb({w+s,temp});
    }
    sort(all(vp),cmp);
    dp.resize(n+1,vector<ll>(mx+1,-1));

    //since i'm not able to decide what initial value is to be passed for can_take var, let's try all values then
    ll ans=0;
    for(ll i=0;i<n;++i){
        //cout<<ans<<" ";
        ans=max(ans,vp[i].ss[2]+recur(i+1,vp[i].ss[1]));
    }
    cout<<ans<<endl;

}


int main(){

fast_io;

ll q=1;
//cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}
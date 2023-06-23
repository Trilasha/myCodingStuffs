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





/*
recursive dp
 
ll recur(ll n){
     if(n==0) return 0;
     if(n<0) return 1e5;
     if(dp[n]!=-1) return dp[n];
     ll ans=INT_MAX;
     for(auto it: pyramid){
          if(it>n) break;
          ans=min(ans, recur(n-it)+1);
     }
     return dp[n]=ans;
}
 
*/
// 1 4 10 20
// 1 (1+2)+1   (1+2+3)+((1+2)+1 )
vector<ll> allowed;
void pre(){
    ll start=1;
    ll inc=2;
    ll ins=1;
    ll prev=0;
    while(ins<300000){
        allowed.pb(ins);
        start+=inc;
        inc++;
        prev=ins;
        ins=prev+start;
    }
}

void solve(){
    // printv(allowed);
    // cout<<allowed.size()<<endl;
    ll n;
    cin>>n;
    ll ans=0;
    vector<ll> dp(n+1,1e9);

    dp[0]=0;
    dp[1]=1;
    for(int i=1;i<=n;++i){
        for(int j=0;j<allowed.size();++j){
            if(allowed[j]>i){
                break;
            }
            dp[i]=min(dp[i],dp[i-allowed[j]]+1);
        }
    }

    cout<<dp[n]<<endl;
}


int main(){

fast_io;

ll q=1;
cin>>q;
pre();
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}
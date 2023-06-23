/* ...  risen_ash  ... */

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
#define sp(x)                 fixed<<setprecision(x)
#define md                    998244353
#define modval                1000000007
#define PI                    3.141592653589793238
#define bpl(n)                __builtin_popcountll(n);
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
// define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- 
                !!! DON'T GIVE-UP SEEING LENGTHY QUESTION OR ELSE KEEP REGRETTING LATER !!!                 
  --------------------------------------------------------------------------------------------------------- */




//weight--> price
//val   --> pages;
//mx_wt --> mx_price
//0-1 knapsack



ll n;
vector<ll> v,wt;
vector<vector<ll>> dp;
ll mx=1e3+10;
 
ll recur(ll ind,ll value_left){
    // line
    if(value_left==0)return 0;
 
    if(ind==n)
    return 1e18;
 
    
    if(dp[ind][value_left]!=-1)
    return dp[ind][value_left];
 
    // line
    ll curr_wt=wt[ind];
    ll val=v[ind];
 
    if(val<=value_left){
        return dp[ind][value_left]=min(curr_wt+recur(ind+1,value_left-val),recur(ind+1,value_left));
    }
    else{
        return dp[ind][value_left]=recur(ind+1,value_left);
    }
 
}
void solve(){
    ll mx_wt;
    cin>>n>>mx_wt;
    v.resize(n);
    wt.resize(n);
    dp.resize(n+1,vector<ll>(mx+1,-1));
    fr(i,n){
        cin>>wt[i];
    }
     fr(i,n){
        cin>>v[i];
    }
 
    for(ll i=mx;i>=1;--i){
        if(recur(0,i)<=mx_wt){
            //line
            //cout<<recur(0,i);
            cout<<i<<endl;
            break;
        }
    }
 
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











/*--------------------------------------------------------------------------------------------------------- 
   reference for sequence(NT) --> oeis.org
   log2(x)
   set.lower_bound(x)
   for mod division --> a/b use a*inverse(b) (don't divide simply)
   set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
   gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
   --------------------------------------------------------------------------------------------------------- */
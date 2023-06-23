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
// define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- */




ll n,max_food;
vector<ll> v;
vector<vector<ll>> dp(105,vector<ll>(30010,-1));

ll recur(ll ind,ll curr){
    if(ind>=n){
        return 0;
    }
    if(curr>max_food){
        return -1;
    }
    if(ind==n-1){
        if(curr+v[ind]<=max_food){
            return 1;
        }
        else{
            return 0;
        }
    }

    if(dp[ind][curr]!=-1)return dp[ind][curr];
    ll ans=0;
    ans=max(ans,1+recur(ind+1,curr+(n-ind)*v[ind]));
    ans=max(ans,recur(ind+1,curr));
    return dp[ind][curr]=ans;
}

void solve(){
    cin>>n>>max_food;
    v.resize(n);
    inpv(v);
    cout<<recur(0,0)<<endl;
}


int main(){

fast_io;

freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);

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
   a+b=2⋅(a&b)+a⊕b
   a⊕b=¬(a&b)&(a∣b)
   --------------------------------------------------------------------------------------------------------- */
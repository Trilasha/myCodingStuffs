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








vector<vector<ll>> dp;
ll n;
string s="";

ll recur(ll ind,ll depth){
    if(ind<0)return 0;
    if(dp[ind][depth]!=-1)return dp[ind][depth];
    ll ans=0;

    if(s[ind-1]=='s'){
       ans=(ans+recur(ind-1,depth))%modval;
    }

    ans=(ans+recur(ind-1,depth))%modval;
    return dp[ind][depth]=ans;
}


void solve(){  
    cin>>n;
    vector<string> v(n);
    fr(i,n){
        cin>>v[i];
    }
    fr(i,n){
        s+=v[i];
    }
    dp.resize(n,vector<ll>(n,0));
    dp[0][0]=1;
    //recur(n-1,0);
  
    for(ll i=1;i<n;++i){
        if(s[i-1]=='f'){
            for(ll j=0;j<i;++j){
                dp[i][j+1]=dp[i-1][j];
            }
        }else{
            ll sfsum=0;
            for(ll j=i-1;j>=0;--j){
                sfsum=(sfsum+dp[i-1][j])%modval;
                dp[i][j]=sfsum;
            }
        }
    }

    for(ll i=0;i<n;++i){
        for(ll j=0;j<n;++j){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    ll ans=0;
    for(ll i=0;i<n;++i){
        ans=(ans+dp[n-1][i])%modval;
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












////https://medium.com/spidernitt/problem-c-codeforces-round-455-293ac65c10d6
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
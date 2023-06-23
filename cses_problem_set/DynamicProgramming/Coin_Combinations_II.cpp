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






// dp[i] -> the number of coins required to make sum i
// dp[i] = sum(dp[i-v[j]]) for all j

int dp[101][1000001];
vector<int> v;
int sum,n;
 
int recur(int ind,int sum){
    if(sum==0) return 1;
 
    if(ind>=n){
        return 0;
    }
 
    if(v[ind]>sum){
        return 0;
    }
    
    if(dp[sum][ind]!=-1){
        return dp[sum][ind];
    }
 
    int ans=0;
    if(v[ind]<=sum){
        ans=(ans+recur(ind,sum-v[ind]))%modval;
    }
    ans=(ans+recur(ind+1,sum))%modval;
 
    return dp[sum][ind]=ans;
}
 
void solve(){
    cin>>n>>sum;
    v.resize(n);
    inpv(v);
    memset(dp,0,sizeof(dp));
    sort(all(v));
    //cout<<recur(0,sum)<<endl;
    //dp[i][j] = dp[i][j] + dp[i][j-v[i]] + dp[i+1][j]
    dp[0][0]=1;
    for(int i=0;i<n;++i){
        for(int j=0;j<=sum;++j){
            if(i==0){
                 if(j>=v[i]){
                    dp[i][j]=(dp[i][j]+dp[i][j-v[i]])%modval;
                 }
                 continue;
            }

            if(j>=v[i]){
            dp[i][j]=(dp[i][j]+dp[i][j-v[i]]+dp[i-1][j])%modval;
            }
            else
            dp[i][j]=(dp[i][j] + dp[i-1][j])%modval;
        }
    }

    cout<<dp[n-1][sum]<<endl;

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
   a+b=2⋅(a&b)+a⊕b
   a⊕b=¬(a&b)&(a∣b)
   --------------------------------------------------------------------------------------------------------- */
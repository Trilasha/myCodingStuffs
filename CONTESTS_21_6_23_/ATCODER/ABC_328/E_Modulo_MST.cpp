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






ll n,m,k;
vector<vector<pll>> adj;
map<ll,map<ll,map<ll,ll>>> dp;

ll recur(ll node,ll mask,ll sum){
    if(mask==((1<<n)-1)){
        return sum%k;
    }
    if(dp[node][mask].count(sum)){
        return dp[node][mask][sum];
    }
    ll ans=k;
    for(auto &i: adj[node]){
        ll v=i.ff;
        ll w=i.ss;
        if((mask&(1<<(v-1)))==0){
            ans=min(ans,recur(v,mask|(1<<(v-1)),sum+w));
        }
    }
    return dp[node][mask][sum]=ans;
}

void solve(){
    dp.clear();
    cin>>n>>m>>k;
    adj.resize(n+1);
    for(ll i=0;i<m;++i){
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    ll ans=k;
    for(ll i=1;i<=n;++i){
        ans=min(ans,recur(i,1<<(i-1),0));
    }
    cout<<ans<<endl;
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




struct nCr{
    ll maxx , mod; 
    vector<ll> fact, ifact; 
    inline ll mul(ll a, ll b) { return a *1LL* b % mod ;}
    ll power(ll a, ll n) {
        if(n == 0) return 1 ; 
        int p = power(a, n/2) % mod ; 
        p = mul(p, p) ;  
        return n & 1 ? mul(p, a) : p ; 
    }
    int invMod(int a) {return power(a,mod-2);}
    void pre() {
        fact[0] = 1 ;
        for(int i = 1;i< maxx;++i) fact[i] = mul(i, fact[i-1]) ;
        ifact[maxx-1] = invMod(fact[maxx-1]) ; 
        for(int i = maxx-1 ; i>0 ;--i) ifact[i-1] = mul(ifact[i], i) ;
    }
    nCr(int _mxN, int _M) {
        maxx = _mxN + 1; 
        mod = _M ; 
        fact.resize(maxx) ; 
        ifact.resize(maxx) ;
        pre() ;  
    }
    ll C(ll n, ll r) {
        if (n < r || r < 0 || n < 0) return 0;
        return mul(fact[n], mul(ifact[r], ifact[n-r])) ;
    }
};
//maxx N we need
//const int N = 100;
// initialise nCr struct
// nCr comb(N , mod);



#define ll long long 
const ll mod=1e9+7;

class Solution {
public:
      ll recur(ll curr,ll l,ll e,ll t,ll n,vector<vector<vector<vector<ll>>>> &dp){
        // cout<<curr<<" "<<l<<" "<<e<<" "<<t<<endl;
        if(curr>=n){
            if(l<1 || e<2 || t<1) return 0;
            return 1;
        }
        if(dp[curr][l][e][t]!=-1) return dp[curr][l][e][t];
        ll ans=0;
        for(char ch='a';ch<='z';++ch){
            ll l=min(1LL,l+(ch=='l'));
            ll e=min(2LL,l+(ch=='e'));
            ll t=min(1LL,l+(ch=='t'));
            ans=(ans+recur(curr+1,l,e,t,n,dp))%mod;
        }
        return dp[curr][l][e][t]=ans;
    }

    int stringCount(int n) {
        vector<vector<vector<vector<ll>>>> dp(n+1,vector<vector<vector<ll>>>(3,vector<vector<ll>>(4,vector<ll>(3,-1))));
        return recur(0,0,0,0,n,dp);
    }
};
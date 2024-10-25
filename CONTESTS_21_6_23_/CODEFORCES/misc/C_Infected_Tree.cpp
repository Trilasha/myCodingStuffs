/*
    Trilasha Mazumder
*/

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
// insead of bpow use shift operators when b=2 to avoid tle 
// do not perform more than one optimal choice/ops in a single step/loop otherwise break your head with WA





void solve(){
    ll n;
    cin>>n;
    vector<vector<ll>> adj(n+1);
    fr(i,n-1){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<ll> dp(n+1),subtree(n+1);
    vector<vector<ll>> dp2(n+1,vector<ll>(2));
    function<void(ll,ll)> dfs = [&](ll u,ll p){
        subtree[u]=1;
        ll ind=0;
        for(auto v: adj[u]){
            if(v==p) continue;
            dp2[u][ind++]=v;
            dfs(v,u);
            subtree[u]+=subtree[v];
        }
        if(subtree[u]==1){
            dp[u]=0;
        }else if(subtree[u]==2){
            dp[u]=subtree[dp2[u][0]]-1;
        }else{
            dp[u]=max(subtree[dp2[u][0]]-1LL+dp[dp2[u][1]],subtree[dp2[u][1]]-1LL+dp[dp2[u][0]]);
        }
        // cout<<u<<" "<<dp[u]<<" "<<subtree[u]<<endl;
    };
    dfs(1,0);
    cout<<dp[1]<<endl;
}


int main(){

fast_io;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

ll q=1;
cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}


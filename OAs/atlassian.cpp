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


vector<vector<pll>> adj;
vector<ll> dp,ans;

ll dfs(ll node,ll par){
    for(auto &i:adj[node]){
        ll child=i.first;
        ll wt=i.second;
        if(child!=par){
            dp[node]+=dfs(child,node);
            dp[node]+=wt;
        }
    }
    return dp[node];
}

void dfs2(ll node,ll par){
    for(auto &i:adj[node]){
        ll child=i.first;
        ll wt=i.second;
        if(child!=par){
            ans[child]=ans[node]+((wt==0)?1:-1);
            dfs2(child,node);
        }
    }
}

void solve(){
    ll n,e;
    cin>>n>>e;
    vector<ll> from(e),to(e);
    inpv(from);inpv(to);
    adj.resize(n+1);
    for(ll i=0;i<e;++i){
        ll u=from[i];
        ll v=to[i];
        adj[u].pb({v,0});
        adj[v].pb({u,1});
    }
    dp.resize(n+1);
    dfs(1,0);
    ans.resize(n+1);
    ans[1]=dp[1];
    dfs2(1,0);
    for(ll i=1;i<=n;++i){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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



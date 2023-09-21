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
 
 
 
vector<vector<ll>> adj,adjRev;
vector<ll> vis,order,ans;

void dfs(ll node,ll pass,ll component){
    vis[node]=1;
    vector<ll> newAdj=((!pass)?adj[node]:adjRev[node]);
    for(auto &i:newAdj){
        if(!vis[i]) dfs(i,pass,component);
    }
    if(!pass)order.pb(node);
    ans[node]=component;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    adj.resize(n+1);
    adjRev.resize(n+1);
    vis.resize(n+1);
    ans.resize(n+1);
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adjRev[v].pb(u);
    }
    for(ll i=1;i<=n;++i){
        if(!vis[i]){
            dfs(i,0,0);
        }
    }
    reverse(all(order));
    vis.assign(n+1,0);
    ll components=1;
    for(auto &node:order){
        if(!vis[node]){
            dfs(node,2,components);
            components++;
        }
    }
    cout<<components-1<<endl;
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
 
 
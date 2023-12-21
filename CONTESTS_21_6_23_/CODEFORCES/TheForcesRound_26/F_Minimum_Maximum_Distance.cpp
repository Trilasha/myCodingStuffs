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






vector<vector<ll>> adj;
vector<ll> max_dis,depth,deptha,depthb,marked;
ll node1,node2,n,k;

void dfs(ll node,ll par){
    for(auto &child:adj[node]){
        if(child==par)continue;
        depth[child]=depth[node]+1;
        dfs(child,node);
    }
}
void find_diameter_nodes(){
   ll max_depth=0;
   dfs(1,-1);
   ll ind=-1;
   for(ll i=1;i<=n;++i){
        if(depth[i]>=max_depth && marked[i]){
            max_depth=depth[i];
            ind=i;
        }
        depth[i]=0;
   }
   max_depth=0;
   node1=ind;
   dfs(ind,-1);
   for(ll i=1;i<=n;++i){
       if(depth[i]>=max_depth && marked[i]){
           max_depth=depth[i];
           node2=i;
       }
   }
 
}
void dfs1(ll node,ll par){
    for(auto &child:adj[node]){
        if(child==par)continue;
        deptha[child]=deptha[node]+1;
        dfs1(child,node);
    }
}
void dfs2(ll node,ll par){
    for(auto &child:adj[node]){
        if(child==par)continue;
        depthb[child]=depthb[node]+1;
        dfs2(child,node);
    }
}
 
 
 

void solve(){
    cin>>n>>k;
    marked.assign(n+1,0ll);
    fr(i,k){
        ll x;
        cin>>x;
        marked[x]=1;
    }
    adj.assign(n+1,{});
    max_dis.assign(n+1,0ll);
    depth.assign(n+1,0ll);
    for(ll i=1;i<=n-1;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    find_diameter_nodes();
    // cout<<node1<<" "<<node2<<endl;

    deptha.assign(n+1,0ll);
    depthb.assign(n+1,0ll);
    dfs1(node1,-1);
    dfs2(node2,-1);
    
    for(ll i=1;i<=n;i++){
        max_dis[i]=max(deptha[i],depthb[i]);
    }
    ll ans=1e10;
    for(ll i=1;i<=n;++i){
        ans=min(ans,max_dis[i]);
    }
    cout<<ans<<endl;
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


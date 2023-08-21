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



vector<vector<ll>> adj,adjRev,allBridges;
vector<ll> vis,order,ans;


ll timer=0; 
void dfs2(ll node,ll par,vector<ll> &tin,vector<ll> &lowestTime){
    vis[node]=1;
    timer++;
    for(auto &adjNode:adj[node]){
        if(!vis[adjNode]){
            tin[adjNode]=timer;
            lowestTime[adjNode]=timer;
            dfs2(adjNode,node,tin,lowestTime);
        }
        if(lowestTime[adjNode]>tin[node]){
            allBridges.push_back({node,adjNode});
        }else if(adjNode!=par){
            lowestTime[node]=min(lowestTime[node],lowestTime[adjNode]);
        }
    }
}
void dfs(ll node,ll pass,ll component){
    vis[node]=1;
    vector<ll> newAdj=((!pass)?adj[node]:adjRev[node]);
    for(auto &i:newAdj){
        if(!vis[i]) dfs(i,pass,component);
    }
    if(!pass)order.pb(node);
    ans[node]=component;
}

ll dfs3(ll node){
    vis[node]=1;
    ll sum=0;
    for(auto &i:adj[node]){
        if(!vis[i]){
            sum=max(sum,dfs3(i));
        }
    }
    return sum+ans[node];
}

void solve(){
    ll n,m;
    cin>>n>>m;
    adj.resize(n+1);
    adjRev.resize(n+1);
    vis.resize(n+1);
    ans.resize(n+1);
    vector<ll> cost(n+1);
    fr(i,n){
        cin>>cost[i+1];
    }
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
    // printv(ans);
    vis.assign(n+1,0);
    vector<ll> tin(n+1),lowestTime(n+1);
    for(int x=1;x<=n;++x){
    if(!vis[x]){
        tin[x]=timer;
        lowestTime[x]=timer;
        dfs2(x,-1,tin,lowestTime);
    }
   }
   map<ll,ll> mp;
   for(ll i=1;i<=n;++i){
    mp[ans[i]]+=cost[i];
   }
   for(ll i=1;i<=n;++i){
    ans[i]=mp[ans[i]];
   }
//    printv(ans);
    adj.assign(n+1,vector<ll>());
    for(auto &i:allBridges){
        adj[i[0]].pb(i[1]);
        adj[i[1]].pb(i[0]);
    }
    for(ll i=0;i<n;++i){
        for(auto &j:adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    vis.assign(n+1,0);
    ll anss=0;
    for(ll i=1;i<=n;++i){
        if(!vis[i] && !adj[i].empty()){
            anss=max(anss,dfs3(i));
        }
    }
   cout<<anss<<endl;

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






/*----------------------------------------------------------------------------------------------------------- */
// clear adj and visited vector declared globally after each test case 
// if input newly taken then use 'resize' or else 'assign' (for dp and graphs)
//    BINARY SEARCH ~ 2-PNTS ~ DP 
//    reference for sequence(NT) --> oeis.org
//    log2(x)
//    set.lower_bound(x)
//    for mod division --> a/b use a*inverse(b) (don't divide simply)
//    set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
//    gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
//    if nlogn approach gives tle, go for O(n) don't sit idle (for lb/ub replace set with vector)
//    if 100% sure that chk func is correct then try changing the values of lo/hi in the main func (hit and trial)
/*----------------------------------------------------------------------------------------------------------- */



   

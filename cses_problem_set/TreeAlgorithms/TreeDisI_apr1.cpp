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





// find the two ends of the diameter of the tree
// then for every node its maximum distance would be with either of these two ends of the diameter

vector<vector<ll>> adj;
vector<ll> max_dis,depth,deptha,depthb;
ll node1,node2,n;



//diameter
void dfs(ll node,ll par)
{
    for(auto &child:adj[node])
    {
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
        if(depth[i]>max_depth){
            max_depth=depth[i];
            ind=i;
        }
        depth[i]=0;
   }
 
   max_depth=0;
   node1=ind;

   dfs(ind,-1);
 
   for(ll i=1;i<=n;++i){
       if(depth[i]>max_depth){
           max_depth=depth[i];
           node2=i;
       }
   }

}



//from diameter ends
void dfs1(ll node,ll par)
{
    for(auto &child:adj[node])
    {
        if(child==par)continue;
        deptha[child]=deptha[node]+1;
        dfs1(child,node);
    }
}
void dfs2(ll node,ll par)
{
    for(auto &child:adj[node])
    {
        if(child==par)continue;
        depthb[child]=depthb[node]+1;
        dfs2(child,node);
    }
}




void solve(){
    cin>>n;
    adj.resize(n+1);
    max_dis.resize(n+1);
    depth.resize(n+1);
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    find_diameter_nodes();
    
    //storing the depth of each node from node1 and node2 separately
   // cout<<node1<<" "<<node2<<endl;
    deptha.resize(n+1);
    depthb.resize(n+1);
    dfs1(node1,-1);
    dfs2(node2,-1);

    // printv(deptha);
    // printv(depthb);

    for(ll i=1;i<=n;i++){
        max_dis[i]=max(deptha[i],depthb[i]);
    }

    for(ll i=1;i<=n;++i){
        cout<<max_dis[i]<<" ";
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











/*--------------------------------------------------------------------------------------------------------- 
   reference for sequence(NT) --> oeis.org
   log2(x)
   set.lower_bound(x)
   for mod division --> a/b use a*inverse(b) (don't divide simply)
   set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
   gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
   --------------------------------------------------------------------------------------------------------- */
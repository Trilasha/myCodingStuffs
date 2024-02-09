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


struct LCA{
    vector<vector<int>> up;
    vector<int> tin, tout, distance;
    int timer;
    vector<int> parent;
    LCA(int n) {
        timer = 0;
        tin.resize(n);
        tout.resize(n);
        up.assign(n, vector<int>(21, -1));
        distance.assign(n, 0);
        parent.assign(n+1,0);
    }
    void dfs(int v, int p, vector<vector<int>> &adj, int dis) {
        distance[v]=dis;
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i < 21; i++)
            up[v][i] = up[up[v][i - 1]][i - 1];
        for (int u : adj[v]) {
            if (u != p){
                parent[u]=v;
                dfs(u, v, adj, dis+1);
            }
        }
        tout[v] = ++timer;
    }
    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    int lca(int u, int v) {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = 20; i >= 0; i--) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }
    int dist(int u, int v) {
        int w = lca(u, v);
        return abs(distance[u] + distance[v] - 2*distance[w]);
    }
};
 
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    vector<int> depth(n+1,0),node;
    fr(i,n-1){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    function<void(int,int,int)> dfs=[&](int u,int p,int d){
        depth[u]=d;
        for(auto v: adj[u]){
            if(v!=p)
                dfs(v,u,d+1);
        }
    };
    dfs(1,-1,0);
    int max_depth=0;
    int ind=-1;
    int node1=-1,node2=-1;
   for(int i=1;i<=n;++i){
        if(depth[i]>max_depth){
            max_depth=depth[i];
            ind=i;
        }
        depth[i]=0;
   }
   max_depth=0;
   node.pb(ind);
   dfs(ind,-1,0);

   for(int i=1;i<=n;++i){
        if(depth[i]>max_depth){
            max_depth=depth[i];
            ind=i;
        }
        depth[i]=0;
   }
   node.pb(ind);

   LCA tree(n+1);
   tree.dfs(1,1,adj,0);

   int a=node[0],b=node[1];
   map<pair<int,int>,int> mp;
   int lc=tree.lca(a,b);
   int dis=0,node3=0;

   //
   vector<int> vis(n+1);
   queue<pair<int,int>> q;
   q.push({0,a});
   vis[a]=1;
   while(a!=lc){
        int p=tree.parent[a];
        q.push({0,p});
        vis[p]=1;
        a=p;
   }
    q.push({0,b});
    vis[b]=1;
    while(b!=lc){
          int p=tree.parent[b];
          if(p==lc)break;
          q.push({0,p});
          vis[p]=1;
          b=p;
    }
    while(!q.empty()){
        int u=q.front().ss;
        int d=q.front().ff;
        q.pop();
        if(d>dis){
            dis=d;
            node3=u;
        }
        vis[u]=1;
        for(auto v: adj[u]){
            if(!vis[v]){
                q.push({d+1,v});
            }
        }
    }
    if(dis==0){
        for(int i=1;i<=n;++i){
            if(i!=node[0] && i!=node[1]){
               node3=i;
               break;
            }
        }
    }
    cout<<max_depth+dis<<endl;
    cout<<node[0]<<" "<<node[1]<<" "<<node3<<endl;

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


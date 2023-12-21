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
    vector<pair<int,int>> parent;
    int timer;
    LCA(int n) {
        timer = 0;
        tin.resize(n);
        tout.resize(n);
        up.assign(n, vector<int>(21, -1));
        distance.assign(n, 0);
        parent.resize(n+1);
    }
    void dfs(int v, int p, vector<vector<int>> &adj, int dis) {
        distance[v]=dis;
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i < 21; i++)
            up[v][i] = up[up[v][i - 1]][i - 1];
        for (auto u : adj[v]) {
            if (u != p){
                // parent[u.first]={v,u.second};
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
   vector<ll> parent(n+1);
   fr(i,n-1){
        int x,y;
        cin>>x>>y;
        x--,y--;
        adj[x].pb(y);
        adj[y].pb(x);
   }
   LCA tree(n);
   tree.dfs(0,0,adj,0);
   vector<int> mp(n+3);
   function<void(int,int,int)> dfs1=[&](int u,int p,int dis){
        mp[u+1]=dis;
        for(auto v: adj[u]){
            if(v!=p){
                parent[v]=u;
                dfs1(v,u,dis+1);
            }
        }
   };
   dfs1(0,0,0);
   int q;
   cin>>q;
   while(q--){
        int a,b;
        cin>>a>>b;
        a--,b--;
        if((mp[a+1]%2)!=(mp[b+1]%2)){
            cout<<"Yes"<<endl;
            continue;
        }
        int dis=tree.dist(a,b);
        cout<<"No"<<endl;
        cout<<1<<" "<<dis+1<<endl;
   }
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


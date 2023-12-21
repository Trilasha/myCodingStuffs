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
#define endl                " \n"
/* ---------------------------------------------------------------------------------------------------------- */
 

 
class LCA{
    public:
    vector<vector<int>> up;
    vector<int> tin, tout, distance;
    int timer;
    vector<vector<int>>store;
    LCA(int n) {
        timer = 0;
        tin.resize(n+1);
        tout.resize(n+1);
        up.assign(n+1, vector<int>(32, -1));
        distance.assign(n+1, 0);
        store.assign(n+1,{});
    }
    void dfs(int v, int p, vector<vector<int>> &adj, int dis) {
        distance[v]=dis;
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i < 31; i++)
            up[v][i] = up[up[v][i - 1]][i - 1];
        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v, adj, dis+1);
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
        for (int i = 30; i >= 0; i--) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }
    int dist(int u, int v) {
        int w = lca(u, v);
        return abs(distance[u] + distance[v] - 2*distance[w]);
    }
    int kth_ancestor(int node,int k){
        if(distance[node]<k){
            return -1;
        }
        for(int i=0;i<=30;++i){
            if(k&(1<<i)){
                node=up[node][i];
            }
        }
        return node+1;
    }
};
 
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    fr(i,n-1){
        int x,y;
        cin>>x>>y;
        x--,y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    LCA tree(n);
    tree.dfs(0,0,adj,0);
    int q;
    cin>>q;
    while(q--){
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        int get_lca=tree.lca(a,b);
        if(tree.dist(a,b)<=c){
            cout<<b+1<<endl;
        }else{
            int dis=tree.dist(a,get_lca);
            if(c<=dis){
                cout<<tree.kth_ancestor(a,c)<<endl;
            }else{
                c-=dis; 
                int d=tree.dist(b,get_lca);
                d-=c;
                cout<<tree.kth_ancestor(b,d)<<endl;
            }
        }
    }
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
 

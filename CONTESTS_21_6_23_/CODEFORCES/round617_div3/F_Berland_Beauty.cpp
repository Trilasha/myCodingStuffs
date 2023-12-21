#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define fast_io               ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl       "\n"
/*-----------------------------------------------------------------------------------------------------------*/

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
    void dfs(int v, int p, vector<vector<pair<int,int>>> &adj, int dis) {
        distance[v]=dis;
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i < 21; i++)
            up[v][i] = up[up[v][i - 1]][i - 1];
        for (auto u : adj[v]) {
            if (u.first != p){
                parent[u.first]={v,u.second};
                dfs(u.first, v, adj, dis+1);
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
 
int main(){
    int n;
    cin>>n;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<int> edges(n+1,1);
    vector<int> parent(n+1);
    for(int i=0;i<n-1;++i){
        int x,y;
        cin>>x>>y;
        x--,y--;
        adj[x].push_back({y,i});
        adj[y].push_back({x,i});
    }
    LCA tree(n);
    tree.dfs(0,0,adj,0);
    int m;
    cin>>m;
    vector<pair<int,pair<int,int>>> vp;
    for(int i=0;i<m;++i){
        int a,b,w;
        cin>>a>>b>>w;
        a--,b--;
        vp.push_back({w,{a,b}});
    }
    sort(vp.begin(),vp.end(),greater<pair<int,pair<int,int>>>());

    function<void(int,int,int,int&,int&)> dfs=[&](int get_lca,int node,int wt,int &ok,int &cnt){
        if(node==get_lca)return;
        pair<int,int> p1=tree.parent[node];
        int par=p1.first;
        int edge=p1.second;
        if(edges[edge]>wt)ok++;
        else edges[edge]=wt;
        cnt++;
        dfs(get_lca,par,wt,ok,cnt);
    };
    for(int i=0;i<m;++i){
        int a=vp[i].second.first;
        int b=vp[i].second.second;
        int wt=vp[i].first;
        int get_lca=tree.lca(a,b);
        int ok=0,cnt=0;
        dfs(get_lca,a,wt,ok,cnt);
        dfs(get_lca,b,wt,ok,cnt);
        // cout<<mp[{0,1}]<<endl;
        if(ok==cnt){
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int i=0;i<n-1;++i){
        cout<<edges[i]<<" ";
    }
    cout<<endl;
    return 0;
}
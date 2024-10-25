/*
The depth of forest at which a maximum number of nodes are present. If multiple depths have the same number of nodes then deepest depth should be printed. N can be very large. Aim for an algorithm with a time complexity of O(N).
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long 

struct LCA{
    vector<vector<ll>> up;
    vector<ll> tin, tout, distance;
    ll timer;
    LCA(ll n) {
        timer = 0;
        tin.resize(n);
        tout.resize(n);
        up.assign(n, vector<ll>(21, -1));
        distance.assign(n, 0);
    }
    void dfs(ll v, ll p, vector<vector<ll>> &adj, ll dis) {
        distance[v]=dis;
        tin[v] = ++timer;
        up[v][0] = p;
        for (ll i = 1; i < 21; i++)
            up[v][i] = up[up[v][i - 1]][i - 1];
        for (ll u : adj[v]) {
            if (u != p)
                dfs(u, v, adj, dis+1);
        }
        tout[v] = ++timer;
    }
    bool is_ancestor(ll u, ll v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    ll lca(ll u, ll v) {
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
};

class DSU{
    vector<ll> par,size;
public:
    ll tot_components;
    DSU(ll n){
        size.resize(n+1,1);
        par.resize(n+1);
        for(ll i=1;i<=n;++i)
        par[i]=i;
        tot_components=n;
    }
    ll findPar(ll node){
        if (node==par[node])
        return node;
        return par[node]=findPar(par[node]);
    }
    ll getsize(ll node){
        return size[findPar(node)];
    }
    void unite(ll u,ll v){
        ll ult_u=findPar(u);
        ll ult_v=findPar(v);
        if(ult_u==ult_v)return;
        if(size[ult_u]<size[ult_v]){
            size[ult_v]+=size[ult_u];
            par[ult_u]=ult_v;
        }else{
            size[ult_u]+=size[ult_v];
            par[ult_v]=ult_u;
        }
        tot_components--;
    }
};
 


int main(){
    ll q;
    cin>>q;
    while(q--){
        ll n;
        cin>>n;
        vector<ll> v(n);   
        for(auto &i:v){
            cin>>i;
        }
        pair<ll,ll> p;
        cin>>p.first>>p.second;
        vector<vector<ll>> adj(n+1);
        vector<ll> root;
        DSU ds(n);

        for(ll i=0;i<n;++i){
            if(v[i]==-1){
                root.push_back(i);
            }else{
                ds.unite(i+1,v[i]+1);
                adj[v[i]].push_back(i);
                adj[i].push_back(v[i]);
            }
        }
        if(ds.findPar(p.first+1)!=ds.findPar(p.second+1)){
            cout<<-1<<endl;
        }else{
            LCA tree(n);
            for(auto &i:root){
                tree.dfs(i,i,adj,0);
            }
            ll anc=tree.lca(p.first,p.second);
            cout<<anc<<endl;
        }
    }
    return 0;
}
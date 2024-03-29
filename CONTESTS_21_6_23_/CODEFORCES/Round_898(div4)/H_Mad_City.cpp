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






void dfs(ll node,ll par,ll time,vector<vector<ll>> &adj,vector<ll> &vis,ll &Vtime,ll &Vnode,vector<ll> &dp){
    vis[node]=1;
    dp[node]=time;
    for(auto child: adj[node]){
        if(vis[child] && child!=par && Vtime==-1){
            //cout<<child<<" "<<node<<endl;
            Vnode=child;
            Vtime=dp[child];
        }
        if(!vis[child]){
            dfs(child,node,time+1,adj,vis,Vtime,Vnode,dp);
        }
    }
}
void dfs2(ll node,ll par,ll time,vector<vector<ll>> &adj,vector<ll> &vis,ll &Mtime,ll Vnode){
    vis[node]=1;
    if(node==Vnode){
        // cout<<time<<endl;
        Mtime=time;
    }
    for(auto child: adj[node]){
        if(!vis[child]){
            dfs2(child,node,time+1,adj,vis,Mtime,Vnode);
        }
    }
}
void solve(){
    ll n,M,V;
    cin>>n>>M>>V;
    vector<vector<ll>> adj(n+1);
    fr(i,n){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    ll Vnode=-1,Mtime=-1,Vtime=-1;
    vector<ll> vis(n+1,0);
    vector<ll> dp(n+1);
    dfs(V,0,0,adj,vis,Vtime,Vnode,dp);
    vis.clear();
    vis.assign(n+1,0);
    //cout<<Vnode<<" "<<Vtime<<endl;
    dfs2(M,0,0,adj,vis,Mtime,Vnode);
    //cout<<Mtime<<endl;
    if(M==V){
        cout<<"NO"<<endl;
        return;
    }
    //cout<<Vtime<<" "<<Mtime<<endl;

    cout<<((Vtime<Mtime)?"YES":"NO")<<endl;
}


int main(){

fast_io;

ll q=1;
cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}


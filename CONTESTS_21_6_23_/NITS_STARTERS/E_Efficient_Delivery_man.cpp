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





pair<ll,ll> dfs(ll node,ll par,vector<vector<ll>> &adj,set<ll> &N,ll &cost){
    pair<ll,ll> p1={0,0};
    if(N.count(node)){
        p1.second=1;
    }
    for(auto child: adj[node]){
        if(child!=par){
            pll C=dfs(child,node,adj,N,cost);
            if(C.second)p1.first+=C.first+2*cost;
            p1.second|=C.second;
        }
    }
    return p1;
}
void solve(){
    ll n,cost,nodes,start;
    cin>>n>>cost>>nodes>>start;
    set<ll> N;
    fr(i,nodes){
        ll x;
        cin>>x;
        N.insert(x);
    }
    vector<vector<ll>> adj(n+1);
    fr(i,n-1){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    pll p=dfs(start,-1,adj,N,cost);
    cout<<p.first<<endl;
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


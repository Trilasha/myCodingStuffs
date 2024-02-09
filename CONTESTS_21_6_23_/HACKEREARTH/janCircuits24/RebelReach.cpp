/*
    When talent doesn't work hard then hardwork beats talent...
    ...hardwork always pays off
*/
 
 
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
// insead of bpow use shift operators when b=2 to avoid tle 
// do not perform more than one optimal choice/ops in a single step/loop otherwise break your head with WA
 
 
 
 
vector<vector<ll>> adj,up;
vector<ll> val,store;

void dfs(ll node,ll parent,ll value){
   store[node]=value;
    for(auto &i:adj[node]){
        if(i!=parent){
            dfs(i,node,store[node]+val[i]);
        }
    }
}
void dfs2(ll node,ll par,ll level){
    up[node][0]=par;
    for(ll i=1;i<=20;++i){
        if(up[node][i-1]!=-1){
            up[node][i]=up[up[node][i-1]][i-1];
        }
    }
    for(auto child:adj[node]){
        if(child!=par){
            dfs2(child,node,level+1);
        }
    }
}
ll calc(ll u,ll v){
    return store[u]-store[v];
}
ll find(ll u,ll x){
    for(ll i=20;i>=0;--i){
        ll temp=up[u][i];
        ll current=calc(u,temp);
        if((current+val[temp])<x){
            x-=current;
            u=temp;
        }
    }
    if(val[u]>=x) return u;
    return up[u][0];
}

void solve(){
    ll n;
    cin>>n;
    adj.assign(n+1,vector<ll>());
    up.assign(n+1,vector<ll>(21,-1));
    store.assign(n+1,0LL);
    val.assign(n+1,0LL);
    fr(i,n-1){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    fr(i,n){
        cin>>val[i+1];
    }

    dfs(1,0,val[1]);
    dfs2(1,1,0);
 
    ll q;
    cin>>q;
    while(q--){
        ll node,X;
        cin>>node>>X;
        cout<<find(node,X)<<endl;
        // line
    }
    // printv(store);
 
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
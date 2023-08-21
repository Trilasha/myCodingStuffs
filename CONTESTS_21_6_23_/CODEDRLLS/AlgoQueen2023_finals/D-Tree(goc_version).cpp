#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                " \n"
#define F                   first
#define S                   second
#define sz(x)               (int)(x).size()   
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end()
#define rep(i, a, b)        for (int i = a; i < (b); ++i)
#define fast_io             cin.tie(0)->sync_with_stdio(0);cin.exceptions(cin.failbit);

using ll  = long long;
using ull = unsigned long long;
using lld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vl  = vector<ll>;
using vi  = vector<int>;

vector<vl> v,adj;
int timer=0;
int n;
vl in,out,cost;
void dfs(int node,int par,int dist){
    in[node]=timer++;
    v[dist].pb(in[node]);
   
    for(auto i:adj[node]){
        if(i==par) continue;
        dfs(i,node,dist+1);
    }

    out[node]=timer;
}


int ans=0;
void calc(int node,int par, int dist){

    int x=dist*2+1;
    if(x>n) return;
    int l=lower_bound(all(v[x]),in[node])-v[x].begin();
    int r=lower_bound(all(v[x]),out[node])-v[x].begin();
    ans+= (r-l)*cost[node];
    for(auto child:adj[node]){
        if(child==par) continue;
        calc(child,node,dist+1);
    }

}


void dk(){
      cin>>n;
      v.clear();
      adj.assign(n+1,vl());
      in.assign(n+1,0);
      out.assign(n+1,0);
      cost.resize(n+1);
      v.resize(n+1);
      rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
      }
      rep(i,1,n+1) cin>>cost[i];
      dfs(1,0,1);
      rep(i,0,n+1) sort(all(v[i]));
      calc(1,0,0);
      cout<<ans<<endl;
}



int main()
{ 
    fast_io;
  
    int n=1;
    cin>>n;
    for(int i=0;i<n;i++){
    dk();
   }
  return 0;
}
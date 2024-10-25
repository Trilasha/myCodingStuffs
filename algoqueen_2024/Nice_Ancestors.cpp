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






void solve(){
  int n,k;
  cin>>n>>k;
  vector<vector<int>>adj(n+1);
  for(int i=1;i<n;i++){
    ll x;
    cin>>x;
    adj[x].pb(i+1);
    adj[i+1].pb(x);
  }
  map<ll,vector<ll>>st;
  vector<ll>ans(n+1,-1);
  function<void(ll,ll,ll)> dfs=[&](ll u,ll p,ll d){
  
    if(st[d].size()!=0){
      ans[u]=st[d].back();
    }
    
    bool flag=0;
    if(u==1 and adj[u].size()==1){
      d++;
      st[d+k-1].pb(u);
      flag=1;
    }
    else if(u!=1 and adj[u].size()==2){
      d++;
      st[d+k-1].pb(u);
      flag=1;
    }
    
    for(auto v:adj[u]){
      if(v!=p){
        dfs(v,u,d);
      }
    }
    if(flag) st[d+k-1].pop_back();
  };

  dfs(1,0,0);
  for(int i=1;i<=n;i++){
    cout<<ans[i]<<" ";
  }
  cout<<endl;
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

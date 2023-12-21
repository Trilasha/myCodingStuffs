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
   ll n;
   cin>>n;
   vector<vector<ll>> adj(n+1);
// //    priority_queue <pll, vector<pll>, greater<pll> > pq;
//     queue<ll> q;
   vector<ll> deg(n+1),depth(n+1);
   fr(i,n-1){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
        deg[x]++;
        deg[y]++;
   }
   ll ans=n;
   ll mxv=0;
   function<ll(ll,ll)> dfs=[&](ll node,ll par){
        ll mx=1;
        // depth[node]=dis;
        for(auto &i:adj[node]){
            if(i!=par){
                if(node!=1){
                    mx+=dfs(i,node);
                }else{
                    mxv=max(mxv,dfs(i,node));
                }
            }
        }
        return mx;
   };
   dfs(1,0);
   ans-=mxv;
   cout<<ans<<endl;
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


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






ll c;
void solve(){
   ll n,k;
   cin>>n>>k;
   vector<vector<ll>> adj(n+1);
   vector<ll> deg(n+1);
   map<pll,ll> mp;
   vector<pll> edges;
   c=0;
   fr(i,n-1){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
        deg[x]++;
        deg[y]++;
        mp[{x,y}]=mp[{y,x}]=i;
        edges.pb({x,y});
   }
   vector<ll> temp=deg;
   sort(all(temp),greater<ll>());
   ll color=temp[k];
//    ll low=1;
//    ll high=0;
//    for(ll i=1;i<=n;++i){
//         high=max(high,deg[i]);
//    }
//    ll color=high;
   
//    function<bool(ll)> check=[&](ll mid){
//         ll cnt=0;
//         for(ll i=1;i<=n;++i){
//             if(deg[i]>mid)cnt++;
//         }
//         return (cnt<=k);
//    };
//    while(low<=high){
//         ll mid=(low+high)/2;
//         if(check(mid)){
//             color=mid;
//             high=mid-1;
//         }else{
//             low=mid+1;
//         }
//    }
   ll start=1;
   for(ll i=1;i<=n;++i){
        if(deg[i]>color){
            start=i;
            break;
        }
   }
   function<void(ll,ll)> dfs=[&](ll node,ll par){
        ll ind=0;
        for(auto &i:adj[node]){
            if(i!=par){
               if(deg[node]>color){
                    if(par==0)mp[{node,par}]=1;
                    mp[{i,node}]=mp[{node,i}]=mp[{node,par}];
                    dfs(i,node);
               }else{
                    ind++;
                    if(mp[{node,par}]==ind) ind++;
                    mp[{node,i}]=mp[{i,node}]=ind;
                    dfs(i,node);
               }
            }
        }
   };
   dfs(start,0);
   cout<<color<<endl;
   for(ll i=0;i<n-1;++i){
        cout<<mp[edges[i]]<<" ";
   }
   cout<<endl;
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


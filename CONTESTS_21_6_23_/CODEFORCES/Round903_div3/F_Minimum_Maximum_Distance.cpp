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
   ll n,m;
   cin>>n>>m;
   vector<ll> v(m+1);
   fr(i,m){
    cin>>v[i+1];
   }
   vector<vector<ll>> adj(n+1);
    fr(i,m){
     ll x,y;
     cin>>x>>y;
     adj[x].pb(y);
     adj[y].pb(x);
    }
    vector<ll> dist(n+1);
    priority_queue<pll> pq;
    for(ll i=1;i<=m;++i){
        pq.push({0,v[i]});
    }
    ll ans=n;
    while(!pq.empty()){
        ll node=pq.top().ss;
        ll d=pq.top().ff;
        pq.pop();
        if(dist[node]>d) continue;
        cout<<node<<" "<<d<<endl;
        for(auto &child: adj[node]){
            if(dist[child]<d+1){
                dist[child]=d+1;
                pq.push({dist[child],child});
            }
        }
    }
    printv(dist);
    for(ll i=1;i<=n;++i){
        ans=min(ans,dist[i]);
    }
    cout<<ans<<endl;
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


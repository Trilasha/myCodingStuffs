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
    vector<vector<pll>> adj(n+1);
    vector<ll> v(n+1);
    fr(i,m){
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a].pb({b,c});
        adj[b].pb({a,c});
    }
    for(ll i=1;i<=n;++i){
        cin>>v[i];
    }
    vector<vector<ll>> dist(n+1,vector<ll>(n+1,1e18));
    ll ans=1e18;
    priority_queue<pair<ll,pll>,vector<pair<ll,pll>>,greater<pair<ll,pll>>> pq;

    pq.push({0,{1,1}});
    while(!pq.empty()){
        auto x=pq.top();
        pq.pop();
        ll curr=x.ss.ff;
        ll node=x.ss.ss;
        ll cost=x.ff;
        if(dist[node][curr]<cost){
            continue;
        }
        dist[node][curr]=cost;
        for(auto i: adj[node]){
            ll nextcost=i.ss*v[curr];
            ll send=curr;
            if(v[curr]>v[i.ff]){
                send=i.ff;
            }
            if(dist[i.ff][send]>dist[node][curr]+nextcost){
                dist[i.ff][send]=dist[node][curr]+nextcost;
                pq.push({dist[i.ff][send],{send,i.ff}});
            }
        }
    }
    for(ll i=1;i<=n;++i){
        ans=min(ans,dist[n][i]);
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


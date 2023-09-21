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




vector<ll> dijkstra(vector<vector<pair<ll,ll>>> &adj,ll n,ll S){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll,ll>>> pq;
    vector<ll> dis(n + 1, 1e18);
    dis[S] = 0;
    pq.push({0, S});
    while (!pq.empty()){
        ll distance = pq.top().first;
        ll node = pq.top().second;
        pq.pop();
        if(distance>dis[node]) continue;
        for (auto &i : adj[node]){
            ll childNode = i.first;
            ll edgeWeight = i.second;
            if (distance + edgeWeight < dis[childNode]){
                dis[childNode] = distance + edgeWeight;
                pq.push({dis[childNode], childNode});
                //parent[childNode] = node;
            }
        }
    }
  return dis;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> adjX(n+1),adjY(n+1);
    vector<ll> A(n),B(n);
    inpv(A);inpv(B);
    fr(i,m){
        ll x,y,wt;
        cin>>x>>y>>wt;
        adjX[x].pb({y,wt});
        adjX[y].pb({x,wt});
    }
    fr(i,m){
        ll x,y,wt;
        cin>>x>>y>>wt;
        adjY[x].pb({y,wt});
        adjY[y].pb({x,wt});
    }
    ll X,Y;
    cin>>X>>Y;
    vector<ll> distX=dijkstra(adjX,n,X);
    vector<ll> distY=dijkstra(adjY,n,Y);

   ll ans=LLONG_MAX;
    for(ll i=1;i<=n;++i){
        for(ll j=1;j*j<=i;++j){
           if(i%j==0){
                if(distX[j]!=1e18 && distY[i]!=1e18)
                ans=min(ans,distX[j]+distY[i]+(A[j-1]*B[i-1]));
                if(distX[i/j]!=1e18 && distY[i]!=1e18)
                ans=min(ans,distX[i/j]+distY[i]+A[(i/j)-1]*B[i-1]);
            }
        }
    }
    cout<<((ans>=LLONG_MAX)?-1:ans)<<endl;
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






   

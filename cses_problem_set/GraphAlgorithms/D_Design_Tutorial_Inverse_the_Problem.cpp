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



//prim's
vector<ll> dijkstra(vector<vector<pair<ll,ll>>> &adj,ll n,ll S){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> dis(n + 1, 1e18);
    vector<ll> parent(n + 1);
 
    for (ll i = 1; i <= n; ++i)
        parent[i] = i;
 
    dis[S] = 0;
    pq.push({0, S});
 
    while (!pq.empty())
    {
        ll distance = pq.top().first;
        ll node = pq.top().second;
        pq.pop();
        if(distance>dis[node]) continue;

        for (auto &i : adj[node])
        {
            ll childNode = i.first;
            ll edgeWeight = i.second;
            if (distance + edgeWeight < dis[childNode])
            {
                dis[childNode] = distance + edgeWeight;
                pq.push({dis[childNode], childNode});
                parent[childNode] = node;
            }
        }
    }
  return dis;
}
 

void solve(){
    ll n;
    cin>>n;
    vector<vector<pll>> adj(n+1),adj2(n+1);
    vector<vector<ll>> v(n+1,vector<ll>(n+1));
    fr(i,n){
        fr(j,n){
            ll wt;
            cin>>wt;
            if(i==j && wt!=0){
                cout<<"NO"<<endl;
                return;
            }
            if(wt!=0)
            adj[i+1].pb({j+1,wt});
            
            v[i+1][j+1]=wt;
        }
    }
    priority_queue<pair<ll,pll>,vector<pair<ll,pll>>,greater<pair<ll,pll>>> pq;
    pq.push({0,{1,0}});
    vector<ll> vis(n+1);
    vector<ll> ok(n+1);
    ok[1]=1;
    while(!pq.empty()){
        ll wt=pq.top().ff;
        ll node=pq.top().ss.ff;
        ll par=pq.top().ss.ss;
        pq.pop();
        if(vis[node]) continue;
        //cerr<<node<<endl;
        vis[node]=1;
        for(auto &i: adj[node]){
            //cerr<<node<<" "<<i.ff<<" "<<vis[i.ff]<<endl;
            if(!vis[i.ff]){
                //cerr<<node<<" "<<i.ff<<" "<<vis[i.ff]<<endl;
                pq.push({i.ss,{i.ff,node}});
                if(ok[i.ff])continue;
                ok[i.ff]=1;
                adj2[node].pb({i.ff,i.ss});
                adj2[i.ff].pb({node,i.ss});
            }
        }
    }
    // for(ll i=1;i<=n;++i){
    //     for(auto &j: adj2[i]){
    //         cout<<i<<" "<<j.ff<<" "<<j.ss<<endl;
    //     }
    // }

    for(ll i=1;i<=n;++i){
        if(!vis[i]){
            cout<<"NO"<<endl;
            return;
        }
    }

    for(ll i=1;i<=n;++i){
        vector<ll> dis=dijkstra(adj2,n,i);
        for(ll j=1;j<=n;++j){
            if(v[i][j]==dis[j])continue;
            else{
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
    
}


int main(){

fast_io;

ll q=1;
//cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}






/*----------------------------------------------------------------------------------------------------------- */
// clear adj and visited vector declared globally after each test case 
// if input newly taken then use 'resize' or else 'assign' (for dp and graphs)
//    BINARY SEARCH ~ 2-PNTS ~ DP 
//    reference for sequence(NT) --> oeis.org
//    log2(x)
//    set.lower_bound(x)
//    for mod division --> a/b use a*inverse(b) (don't divide simply)
//    set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
//    gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
//    if nlogn approach gives tle, go for O(n) don't sit idle (for lb/ub replace set with vector)
//    if 100% sure that chk func is correct then try changing the values of lo/hi in the main func (hit and trial)
/*----------------------------------------------------------------------------------------------------------- */



   

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
//clear adj and visited vector declared globally after each test case 
//if input newly taken then use 'resize' or else 'assign' (for dp and graphs)
//    BINARY SEARCH ~ 2-PNTS ~ DP 
//    reference for sequence(NT) --> oeis.org
//    log2(x)
//    set.lower_bound(x)
//    for mod division --> a/b use a*inverse(b) (don't divide simply)
//    set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
//    gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
//    a+b=2⋅(a&b)+a⊕bs
//    a⊕b=¬(a&b)&(a∣b)
/*----------------------------------------------------------------------------------------------------------- */



/*--------------------------------------------Debug Starts---------------------------------------------------------------------*/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif


void _print(long long t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
//void _print(long long double t) {cerr << t;}
void _print(double t) {cerr << t;}
//void _print(ull t) {cerr << t;}


template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T> void _print(stack<T> v);
template <class T> void _print(list<T> v);
template <class T> void _print(stack<T> v){cerr<< "[" ; while(!v.empty()){_print(v.top()); cerr<< " " ; v.pop();} cerr<< "]" ;}
template <class T> void _print(list<T> v) {cerr << "["; for(auto i: v){_print(i);cerr << " " ;} cerr<< "]";}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*-----------------------------------------------Debug Ends--------------------------------------------------------------------*/


void solve(){
  ll n,m;
  cin>>n>>m;
  vector<vector<ll>> adj(n+1);
  vector<pair<ll,pll>> edges;
  fr(i,m){
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a].pb(b);
        edges.pb({a,{b,c}});
  }

  vector<ll> dist(n+1,LLONG_MIN);
  dist[1]=0;
  fr(i,n-1){
    for(auto x: edges){
        ll a=x.ff;
        ll b=x.ss.ff;
        ll c=x.ss.ss;
        if(dist[a]!=LLONG_MIN){
            dist[b]=max(dist[b],dist[a]+c);
        }
    }
  }

  //check for all the nodes that come in the pathway to n 
  //if there is updation of the distance of any node in the last iteration then ans will be -1
  // we will use bfs to perform this check

  queue<ll> q;
  vector<bool> vis(n+1,false);
  vector<ll> reachable_nodes;
  q.push(1);

  while(!q.empty()){
    ll node=q.front();
    q.pop();
    if(vis[node]) continue;
    vis[node]=true;
    reachable_nodes.pb(node);
    for(auto x: adj[node]){
        if(!vis[x]){
            q.push(x);
        }
    }
  }
  map<ll,ll> mp;
  
  for(auto &x: reachable_nodes){
    //we will perform bfs from each node now and will see if we can reach n from this node
    queue<ll> q;
    vis.clear();
    vis.resize(n+1,false);
    q.push(x);
    while(!q.empty()){
        ll node=q.front();
        q.pop();
        if(vis[node]) continue;
        vis[node]=true;
        for(auto y: adj[node]){
            if(!vis[y]){
                q.push(y);
            }
        }
    }
    if(vis[n]){
        mp[x]++;
    }
  }
  //debug(dist);

  //now the check for the updation in the nth iteration 
    for(auto x: edges){
        ll a=x.ff;
        ll b=x.ss.ff;
        ll c=x.ss.ss;
        if(dist[a]!=LLONG_MIN && dist[b]<dist[a]+c && mp[b]){
                    cout<<-1<<endl;
                    return;
        }
    }

    cout<<dist[n]<<endl;

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






   

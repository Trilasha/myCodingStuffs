/// ------------------------------------HEADER-FILES and ABBREVIATIONS---------------------------- ///
#include <bits/stdc++.h>
using namespace std;
#define ll                    long long
#define ld                    long double
#define pb                    push_back
#define popb                  pop_back
#define lb                    lower_bound
#define ub                    upper_bound
#define umap                  unordered_map
#define uset                  unordered_set
#define ff                    first
#define ss                    second
#define pi                    pair<ll,ll> 
#define maxpq                 priority_queue <ll> pq;
#define minpq                 priority_queue <ll, vector<ll>, greater<ll> > pq; 
/// ------------------------------------PRE-DEFINED VALUES---------------------------------------- ///
#define maxval                1000000007
#define PI                    3.141592653589793238
#define bpl(n)                __builtin_popcountll(n);
/// ------------------------------------TAKING INPUTS--------------------------------------------- ///
#define inp(n)                ll n;cin>>n;
#define inpv(v)               for(auto &x: v) cin>>x;
#define make(arr,n)           ll arr[n]; fr(i,n) cin>>arr[i];
/// ------------------------------------FOR LOOPS AND SORT---------------------------------------- ///
#define fr(i,n)               for (ll i=0;i<n;++i)
#define frs(i,k,n)            for(ll i=k;i<n;++i)
#define fA(i,a,n)             for(ll i=a;i<=(n);++i)
#define fD(i,a,n)             for(ll i=a;i>=(n);--i)
#define dsort(arr)            sort(arr,arr+n,greater<ll>())
#define asort(arr)            sort(arr,arr+n)
#define allasort(str)         sort(str.begin(), str.end())
#define alldsort(str)         sort(str.begin(), str.end(),greater<char>())
#define all(str)              str.begin(), str.end()
#define pll                   pair<ll,ll>
/// ------------------------------------PRINTOUTS------------------------------------------------- ///
#define printv(v)             for(auto &i: v){cout << i << " ";} cout << endl;
#define printmap(mp)          for(auto &i: mp){cout << i.first << " "<<i.second<<endl;}


/// ---------------------------------------------------------------------------------------------- ///
//ceil(log2(x))
    
/// ---------------------------------------------------------------------------------------------- ///
const ll N=1e5+10;
const ll INF=1e9+10;
vector<vector<pair<ll,ll>>> g(N);
vector<ll> level(N,INF);

ll bfs(ll v){
    deque<ll> dq;
    dq.push_back(1);
    level[1]=0;
    while(!dq.empty())
    {
        ll curr=dq.front();
        dq.pop_front();
        for(auto &child:g[curr])
        {
            ll child_node=child.first;
            ll wt=child.second;
            //cout<<curr<<"->"<<level[curr]<<endl;
            //cout<<child_node<<"->"<<level[child_node]<<endl;
            if(level[curr]+wt<level[child_node])
            {
                level[child_node]=level[curr]+wt;
                if(wt==0)
                dq.push_front(child_node);
                else
                dq.push_back(child_node);
            }
            //cout<<child_node<<"->"<<level[child_node]<<endl;
            //cout<<endl;
        }
    }
    return level[v]==INF?-1:level[v];

}
void solve(){
   inp(v);
   inp(e);
   fr(i,e)
   {
    ll x,y;
    cin>>x>>y;
    g[x].pb({y,0});
    g[y].pb({x,1});
   }
   cout<<bfs(v)<<endl;
}
    
int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);

    
ll q;
//cin>>q;
q=1;
while(q--)
{
    solve();
}
    return 0;
}






/*
//
string s=to_string(bitset<64> b(10));

//
using namespace std;
const ll N=1e9+10;
vector<ll> g[N];
bool vis[N];
void dfs(ll vertex)
{
vis[vertex]=true;
for(ll child:g[vertex])
{
    if(vis[child])continue;
    dfs(child);
}
}
*/
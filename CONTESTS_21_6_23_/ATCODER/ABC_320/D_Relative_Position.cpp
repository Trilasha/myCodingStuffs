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




map<pll,pll> mp;
map<ll,pll> cor;
vector<vector<ll>> adj;
vector<ll> vis;


void dfs(ll node){
    vis[node]=1;
    for(auto &i:adj[node]){
        if(!vis[i]){
            cor[i].ff=cor[node].ff+mp[{node,i}].ff;
            cor[i].ss=cor[node].ss+mp[{node,i}].ss;
            dfs(i);
        }
    }
}
void solve(){
    ll n,m;
    cin>>n>>m;
    adj.resize(n+1);
    vis.resize(n+1);
    for(ll i=0;i<m;++i){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        adj[a].pb(b);
        adj[b].pb(a);
        mp[{a,b}]={c,d};
        mp[{b,a}]={-c,-d};
    }
    cor[1]={0,0};
    dfs(1);
    for(ll i=1;i<=n;++i){
        if(vis[i]==0){
            cout<<"undecidable"<<endl;
        }else{
            cout<<cor[i].ff<<" "<<cor[i].ss<<endl;
        }
    }
}


int main(){

fast_io;

ll q=1;
// cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}


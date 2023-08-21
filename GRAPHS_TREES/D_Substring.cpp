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


ll n,q,ans;
string s;
vector<vector<ll>> adj,dp;
map<ll,char> val;
vector<ll> vis;

bool detectCycle(ll node){
    vis[node]=1;
    for(auto child: adj[node]){
        if(!vis[child]){
            if(detectCycle(child)) return true;
        }
        if(vis[child]==1) return true;
    }
    vis[node]=2;
    return false;
}


void dfs(ll node){
    vis[node]=1;
    for(auto child: adj[node]){
        if(!vis[child]){
            dfs(child);
        }
        for(ll i=0;i<=26;++i){
            dp[node][i]=max(dp[node][i],dp[child][i]);
        }
    }
    dp[node][val[node]-'a']++;
    for(ll i=0;i<=26;++i){
        ans=max(ans,dp[node][i]);
    }
}

void solve(){
    cin>>n>>q;
    cin>>s;
    adj.resize(n+1); vis.resize(n+1);
    fr(i,n){
        val[i+1]=s[i];
    }

    fr(i,q){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
    }
    
    for(ll i=1;i<=n;++i){
        if(!vis[i] && detectCycle(i)){
            cout<<-1<<endl;
            return;
        }
    }

    dp.resize(n+1,vector<ll>(27));
    vis.clear();
    vis.resize(n+1);
    ans=1;

    for(ll i=1;i<=n;++i){
        if(!vis[i]){
            dfs(i);
        }
    }
    cout<<ans<<endl;

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
/*----------------------------------------------------------------------------------------------------------- */



   

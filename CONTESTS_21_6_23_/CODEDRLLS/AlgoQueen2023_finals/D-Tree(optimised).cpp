//euler tour + binary search 
//O(n+qlogn) - tc
//O(n) - sc
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


vector<ll> cost,in,out,depth,euler,dp;
vector<vector<ll>> adj,v,pref_sum;
ll timer=1;


void dfs(ll node,ll par,ll dist){
    euler.pb(node);
    in[node]=timer++;
    dp[node]=cost[node];
    depth[node]=dist;
    for(auto i:adj[node]){
        if(i==par) continue;
        dfs(i,node,dist+1);
        dp[node]+=dp[i];
    }

    out[node]=timer++;
}

void solve(){
    ll n,q;
    cin>>n>>q;
    euler.clear();
    cost.resize(n+1);
    adj.assign(n+1,vector<ll>());
    v.assign(n+1,vector<ll>());
    pref_sum.assign(n+1,vector<ll>());
    in.assign(n+1,0);
    out.assign(n+1,0);
    depth.assign(n+1,0);
    dp.assign(n+1,0);

    for(ll i=1;i<=n;++i){
        cin>>cost[i];
    }
   
    for(ll i=0;i<n-1;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1,0,0);
    for(auto &i:euler){
        v[depth[i]].pb(in[i]);
        pref_sum[depth[i]].pb(dp[i]+((pref_sum[depth[i]].empty())?0:pref_sum[depth[i]].back()));
    }

    while(q--){
        ll node,dist;
        cin>>node>>dist;
        if(dist<depth[node]){
            cout<<0<<endl;
            continue;
        }
        ll ans=dp[node];
        ll ind1=lower_bound(all(v[dist+1]),in[node])-v[dist+1].begin();
        ll ind2=lower_bound(all(v[dist+1]),out[node])-v[dist+1].begin();
        ind2--;
        if(ind1<=ind2)
        ans-=pref_sum[dist+1][ind2]-((ind1==0)?0:pref_sum[dist+1][ind1-1]);
        cout<<ans<<endl;
    }

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



   

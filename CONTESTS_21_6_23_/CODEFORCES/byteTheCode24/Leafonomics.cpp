/*
    When talent doesn't work hard then hardwork beats talent...
    ...hardwork always pays off
*/


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
// insead of bpow use shift operators when b=2 to avoid tle 
// do not perform more than one optimal choice/ops in a single step/loop otherwise break your head with WA





void solve(){
    ll n;
    cin>>n;
    vector<vector<pll>> adj(n+1);
    map<ll,ll> mp;
    fr(i,n-1){
        ll x,y,wt;
        cin>>x>>y>>wt;
        adj[x].pb({y,wt});
        adj[y].pb({x,wt});
        // mp[{x,y}]=mp[{y,x}]=wt;
    }
    vector<ll> dp(n+1,1e18),fir(n+1,1e18),sec(n+1,1e18);
    function<void(ll,ll)> recur1=[&](ll node,ll par){
        if(adj[node].size()==1 && node!=1){
            fir[node]=0;
            sec[node]=0;
            return;
        }
        for(auto &i:adj[node]){
            ll x=i.first;
            if(x!=par){
                recur1(x,node);
                if(fir[x]+i.second<fir[node]){
                    sec[node] = fir[node];
				    fir[node] = fir[x] + i.second;
                }else if(fir[x]+i.second<sec[node]){
                    sec[node] = fir[x] + i.second;
                }
            }
        }
    };
    recur1(1,0);
    function<void(ll,ll,ll)> recur2=[&](ll node,ll par,ll fromS){
        dp[node] = min(fromS, fir[node]);
        for (auto &i : adj[node]){
            ll x=i.first;
            ll wt=i.second;
            if (x != par) {
                if (fir[x] + i.second == fir[node])
                    recur2(x, node, min(fromS, sec[node]) + i.second);
                else recur2(x, node, dp[node] + i.second);
            }
        }
    };
    recur2(1,0,1e18);
    fr(i,n){
        cout<<dp[i+1]<<" ";
    }
    cout<<endl;
 
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


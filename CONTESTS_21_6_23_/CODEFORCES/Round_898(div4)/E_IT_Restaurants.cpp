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






ll dfs(ll node,ll par,vector<vector<ll>> &adj,vector<ll> &dp){
    ll ans=1;
    for(auto &i:adj[node]){
        if(i!=par){
            ans+=dfs(i,node,adj,dp);
        }
    }
    return dp[node]=ans;
}
void dfs2(ll node,ll par,ll n,vector<vector<ll>> &adj,vector<ll> &dp,set<pll> &vp){
    ll sum=0;
    //cout<<node<<endl;
    for(auto &i:adj[node]){
        if(i!=par){
            if(node!=1){
                vp.insert({dp[i],n-dp[i]-1});
                vp.insert({n-dp[i]-1,dp[i]});
            }
            if(adj[node].size()>1 && sum>0){
                vp.insert({sum,n-sum-1});
                vp.insert({n-sum-1,sum});
            }
            // cout<<vp.size()<<endl;
            sum+=dp[i];
            dfs2(i,node,n,adj,dp,vp);
        }
    }
    if(node!=1 && adj[node].size()>1 && sum>0){
        vp.insert({sum,n-sum-1});
        vp.insert({n-sum-1,sum});
    }
}
void dfs3(ll node,ll par,ll n,vector<vector<ll>> &adj,vector<ll> &dp,set<pll> &vp){
    ll sum=0;
    for(ll i=adj[node].size()-1;i>=0;--i){
        ll child=adj[node][i];
        if(child!=par){
            if(node!=1){
                vp.insert({dp[child],n-dp[child]-1});
                vp.insert({n-dp[child]-1,dp[child]});
            }
            if(adj[node].size()>1 && sum>0){
                vp.insert({sum,n-sum-1});
                vp.insert({n-sum-1,sum});
            }
            sum+=dp[child];
            dfs3(child,node,n,adj,dp,vp);
        }
    }
    if(node!=1 && adj[node].size()>1 && sum>0){
        vp.insert({sum,n-sum-1});
        vp.insert({n-sum-1,sum});
    }
}
void solve(){
    ll n;
    cin>>n;
    vector<vector<ll>> adj(n+1);
    vector<ll>dp(n+1);
    fr(i,n-1){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1,0,adj,dp);
    // printv(dp);
    set<pll> vp;
    dfs2(1,0,n,adj,dp,vp);
    dfs3(1,0,n,adj,dp,vp);
    cout<<vp.size()<<endl;
    for(auto &i:vp){
        cout<<i.ff<<" "<<i.ss<<endl;
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


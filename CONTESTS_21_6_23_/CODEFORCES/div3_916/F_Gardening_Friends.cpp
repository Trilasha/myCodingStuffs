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
    ll n,k,c;
    cin>>n>>k>>c;
    vector<vector<ll>> adj(n+1);
    fr(i,n-1){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<ll> depth(n+1),deptha(n+1),depthb(n+1);
    ll mx=0;
    ll ind=-1;
    ll a=0,b=0;

    function<void(ll,ll,ll,ll)> dfs=[&](ll node,ll par,ll d,ll ok){
        if(!ok)depth[node]=d;
        else if(ok==1)deptha[node]=d;
        else depthb[node]=d;
        for(auto &i:adj[node]){
            if(i!=par){
                dfs(i,node,d+1,ok);
            }
        }
    };
    dfs(1,0,0,0);
    for(ll i=1;i<=n;++i){
        if(depth[i]>mx){
            mx=depth[i];
            ind=i;
        }
        depth[i]=0;
    }
    a=ind;
    dfs(a,0,0,0);
    mx=0;
    for(ll i=1;i<=n;++i){
        if(depth[i]>mx){
            mx=depth[i];
            ind=i;
        }
        depth[i]=0;
    }
    b=ind;
    dfs(1,0,0,0);
    dfs(a,0,0,1);
    dfs(b,0,0,2);
    ll ans=0;
    for(ll i=1;i<=n;++i){
        ll cost=(max(deptha[i],depthb[i])*k)-(depth[i]*c);
        ans=max(ans,cost);
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


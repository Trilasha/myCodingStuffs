/*
Trilasha Mazumder
2112063

<<<...The morning will come again...
...no darkness, no season can last forever...>>>

*/


/// ------------------------------------HEADER-FILES and ABBREVIATIONS---------------------------- ///
#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp> 


using namespace std;
//using namespace __gnu_pbds;

//typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; 

           
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
#define sp(x)                 fixed<<setprecision(x)
/// ------------------------------------PRE-DEFINED VALUES---------------------------------------- ///
#define md                    998244353
#define modval                1000000007
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
#define all(str)              str.begin(), str.end()
#define pll                   pair<ll,ll>


/// ------------------------------------NUMBER THEORY--------------------------------------------- ///
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll phi(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
ll bpow(ll base,ll power){ll res=1;while(power){if(power&1){res *= base;power--;}else{base *= base;power /=2;}}return res;}
ll expo(ll a, ll b, ll modd) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % modd; a = (a * a) % modd; b = b >> 1;} return res;}

/*
vector<ll> v= sieve(1e5+10);
TC--> nloglogn
*/

/// ------------------------------------PRINTOUTS------------------------------------------------- ///
#define printv(v)             for(auto &i: v){cout << i << " ";} cout << endl;
#define printmap(mp)          for(auto &i: mp){cout << i.first << " "<<i.second<<endl;}
#define printset(st)          for(auto &i: st){cout << i << " ";} cout << endl;
#define line                  cout<<"----------------------------------------"<<endl;

/// ---------------------------------------------------------------------------------------------- ///
//reference for sequence(NT) --> oeis.org






void dfs(vector<vector<pll>> adj,vector<ll> &vis,ll node,ll &ans,vector<ll> &temp)
{
    vis[node]=1;
    temp.pb(node);
    for(auto &i:adj[node])
    {
        ll child=i.ff;
        ll wt=i.ss;
        if(!vis[child])
        {
            ans=min(ans,wt);
            dfs(adj,vis,child,ans,temp);
        }
    }
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> in(n+1,-1),out(n+1,-1);
    vector<pair<pll,ll>> vp;
    vector<vector<pll>> adj(n+1);
    vector<ll> vis(n+1);
    
    fr(i,m)
    {
        ll x,y,e;
        cin>>x>>y>>e;
        out[x]++;
        in[y]++;
        adj[x].pb({y,e});
    }
    ll ans=INT_MAX;

    vector<ll> nodes;
    for(ll i=1;i<=n;++i)
    {
        if(in[i]==-1 && out[i]==0)
        nodes.pb(i);
    }

    // printv(nodes);

    for(ll i=0;i<nodes.size();++i)
    {
        if(!vis[nodes[i]])
        {
            ans=INT_MAX;
            vector<ll> temp;
            dfs(adj,vis,nodes[i],ans,temp);
            //printv(temp);
            //cout<<in[temp[0]]<<"-->"<<out[temp.back()]<<endl;
            if(in[temp[0]]==-1 && out[temp.back()]==-1)
            vp.pb({{temp[0],temp.back()},ans});
        }
    }

    cout<<vp.size()<<endl;
    for(auto &i:vp)
    cout<<i.ff.ff<<" "<<i.ff.ss<<" "<<i.ss<<endl;
}


int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);

ll q=1;
//cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}
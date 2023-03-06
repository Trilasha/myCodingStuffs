/*
Trilasha Mazumder
2112063
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
#define mod                   1000000007
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
ll bpow(int base,int power){int res=1;while(power){if(power&1){res *= base;power--;}else{base *= base;power /=2;}}return res;}
/*
vector<ll> v= sieve(1e5+10);
TC--> nloglogn
*/

/// ------------------------------------PRINTOUTS------------------------------------------------- ///
#define printv(v)             for(auto &i: v){cout << i << " ";} cout << endl;
#define printmap(mp)          for(auto &i: mp){cout << i.first << " "<<i.second<<endl;}
#define printset(st)          for(auto &i: st){cout << i << " ";} cout << endl;
#define line                  cout<<"----------------------------------------"<<endl;
void google(ll t) {cout << "Case #" << t << ": ";}

/// ---------------------------------------------------------------------------------------------- ///
//  v[i]=pow(10,v[i])+0.1; 
//max 1e7 size vector can be created
///vector<vector<int>> M;
//M.resize(m, vector<int>(n));
//binary_search(all(v),5)-->returns boolean value
// iota(all(v),10); -- > o/p--> 10 11 12 13 14 15 16 17 18 19
// a + b = a ^ b + 2 * (a & b)
///------------------------------------------------------------------------------------------------///



const ll N=(1e6)+10;
vector<vector<ll>> adj(N);
vector<ll> depth(N);

void dfs(ll node,ll par)
{
    for(auto &child:adj[node])
    {
        if(child==par)continue;
        depth[child]=depth[node]+1;
        dfs(child,node);
    }
}
void solve()
{
   inp(n);
   if(n==1)
   {
        cout<<1<<endl;
        return;
   }
   fr(i,n-1)
   {
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
   }


   ll max_depth=0;

   dfs(1,-1);
   ll ind=-1;

   vector<pll> vp;
   for(ll i=1;i<=n;++i)
   {
        vp.pb({i,depth[i]});
        if(depth[i]>max_depth)
        {
            max_depth=depth[i];
            ind=i;
        }
        depth[i]=0;
   }

   set<ll> nodes;

   for(ll i=1;i<=n;++i)
   {
    if(vp[i].ss==max_depth)
    nodes.insert(vp[i].ff);
   }
   

   max_depth=0;

   dfs(ind,-1);

   for(ll i=1;i<=n;++i)
   max_depth=max(max_depth,depth[i]);

   for(ll i=1;i<=n;++i)
   {
    if(depth[i]==max_depth)
    nodes.insert(i);
   }


   for(ll i=1;i<=n;++i)
   {
    if(nodes.find(i)!=nodes.end())
    cout<<max_depth+1<<endl;
    else
    cout<<max_depth<<endl;
   }





}
    
int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);

    
ll q=1;
//cin>>q;
for(ll i=0;i<q;i++){
   // google(i+1);
    solve();
}
    return 0;
}

















































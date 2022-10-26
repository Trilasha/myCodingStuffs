/// ------------------------------------------------------------------------------------------------- ///
///////// SUCCESS IS NOT FINAL,FAILURE IS NOT FATAL. IT IS THE COURAGE TO CONTINUE THAT COUNTS //////////
/// ------------------------------------------------------------------------------------------------- ///
    
    
/// ------------------------------------HEADER-FILES and ABBREVIATIONS---------------------------- ///
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define popb pop_back
#define lb lower_bound
#define up upper_bound
#define umap          unordered_map
#define uset          unordered_set
/// ------------------------------------PRE-DEFINED VALUES---------------------------------------- ///
#define maxval                  1000000007
#define PI          3.141592653589793238
/// ------------------------------------TAKING INPUTS--------------------------------------------- ///
#define inp(n)              ll n;cin>>n;
#define inpv(v)              for(auto &x: v) cin>>x;
#define make(arr,n)   ll arr[n]; fr(i,n) cin>>arr[i];
/// ------------------------------------FOR LOOPS AND SORT---------------------------------------- ///
#define fr(i,n)             for (ll i=0;i<n;++i)
#define frs(i,k,n)            for(ll i=k;i<n;++i)
#define fA(i,a,n)   for(ll i=a;i<=(n);++i)
#define fD(i,a,n)   for(ll i=a;i>=(n);--i)
#define dsort(arr)            sort(arr,arr+n,greater<ll>())
#define asort(arr)            sort(arr,arr+n)
#define allasort(str)             sort(str.begin(), str.end())
#define alldsort(str)              sort(str.begin(), str.end(),greater<char>())
#define all            str.begin(), str.end()
/*bool isPrime(ll n)
{
 if(n==1) return false;
if(n==2 || n==3) return true;
if(n%2==0 || n%3==0) return false;
for(ll i=5;i*i<=n;i=i+6)
if(n%i==0 || n%(i+2)==0)
return false;
return true;
}
*/
/*void divisors(ll n)
{ for (ll i = 1; i*i <=n; i++)
{if(n%i==0)
{cout<<i;
if(i!=n/i)
cout<<n/i;
}}}*/
    
    
    
using namespace std;
const ll N=1e5+10;
vector<pair<ll,ll>> g[N];
ll n,m;
map<ll,ll> mp;
vector<ll> sum(N,0);
ll height[N];
void dfs(pair<ll,ll> vertex,pair<ll,ll> par)
{
   if(par.second==0 && sum[par.first]<=m)
        sum[vertex.first]+=vertex.second;
        else
        sum[vertex.first]+=vertex.second+sum[par.first];
       for(pair<ll,ll> child:g[vertex.first])
       {
        if(child.first==par.first) continue;
        dfs(child,vertex);
        height[vertex.first]=max(height[vertex.first],height[child.first]+1);
       }
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    
    cin>>n>>m;
    ll a=1;
    fr(i,n)
    {
       ll x;
       cin>>x;
       mp[a++]=x;
    }
    fr(i,n-1)
    {
        ll x,y;
        cin>>x>>y;
        g[x].pb({y,mp[y]});
        g[y].pb({x,mp[x]});
    }
    dfs({1,mp[1]},{0,-1});
    ll ct=0;
    for (ll i = 1; i <=n; ++i)
    {
      //without the height a bit less memory occupancy occurs
      //if(g[i].size()==1 && i!=1 && sum[i]<=m)
       if(height[i]==0 && sum[i]<=m)
       ct++;
    }
    cout<<ct<<endl;
    return 0;
}
//without height
//171 ms	24100 KB

//with the height
//171 ms	24900 KB

///////////////////////////////////////////////////////////////////////////////

//Siddhid's code
/*
ll n , m ; 
ll ans = 0;
void dfs(vector<vll> &adj , ll parent , vll &is_cat , ll node  , ll cnt , ll g ){
	if(is_cat[node]){
		cnt ++;
	}else{
		cnt = 0;
	}
	g = max(g,cnt);
 
	if(adj[node].size() == 1 && node != 0){
		if(g <= m){
			ans++;
		}
	}
 
	for(auto it: adj[node]){
		if(it != parent){
			dfs(adj , node, is_cat , it , cnt , g);
		}
	}
}
 
void solve(int tc =0)
{
	cin >> n >> m;
	vll is_cat(n);
	for(int i = 0 ;  i < n ; i ++){
		cin >> is_cat[i];
	}
	vector<vector<ll>>adj(n , vector<ll>());
	for(int i = 0 ; i < n-1 ; i++){
		ll x , y; cin >> x >> y;
		x--; y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	ll parent = -1;
	dfs(adj , parent , is_cat , 0 , 0 , 0 );
	cout << ans << endl;
}
 
int main() {
     
    #ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("in.txt" , "r" , stdin);
	//for writing output to output.txt
	freopen("out.txt" , "w" , stdout);
	// for error
	freopen("err.txt" , "w" , stderr);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
 
	ll t = 1;
	//cin >> t;
	for(int i = 1 ; i <= t ; i++){
		//google(i);
		solve();
	}
	return 0;
}
 
//////////62 ms	18800 KB//////////
*/

/*
///////////////////////////// ASHISH'S CODE /////////////////////////////////
const ll q1 = 1e5 ;
vector<vector<ll>> adj(q1);
vector<ll> v; 
ll k;
int dfs(ll node , ll parent, ll count){
   if (v[node-1] == 1) count++; 
   else {
      count = 0;
   }
   if (count > k) return 0;
   int child_count = 0;
   int pass = 0; 
   for (auto i: adj[node]) {
      if (i != parent){
         child_count++; 
         pass += dfs(i, node, count);
      }
   }
   if (child_count == 0) {
      return 1; 
   }
   return pass; 
}
 
 
void solve(int testcase){
   ll n ; cin >> n >> k;
   v.resize(n);
   for (int i = 0; i < n; i++){
      cin >> v[i];
   }
   for(int i = 0; i < n-1; i++){
      ll u , v; cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   cout << dfs(1,-1, 0);
}



//// 77 ms	11900 KB  ////
*/
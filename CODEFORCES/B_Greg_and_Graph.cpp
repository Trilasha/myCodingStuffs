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
#define ff                    first
#define ss                    second
#define maxpq                 priority_queue <ll> pq;
#define minpq                 priority_queue <ll, vector<ll>, greater<ll> > pq; 
#define sp(x)                 fixed<<setprecision(x)
/// ---------------------------------------------------------------------------------------------------------- ///
#define md                    998244353
#define modval                1000000007
#define PI                    3.141592653589793238
#define bpl(n)                __builtin_popcountll(n);
/// ---------------------------------------------------------------------------------------------------------- ///
#define inp(n)                ll n;cin>>n;
#define inpv(v)               for(auto &x: v) cin>>x;
#define make(arr,n)           ll arr[n]; fr(i,n) cin>>arr[i];
/// ---------------------------------------------------------------------------------------------------------- ///
#define fr(i,n)               for (ll i=0;i<n;++i)
#define frs(i,k,n)            for(ll i=k;i<n;++i)
#define all(str)              str.begin(), str.end()
#define pll                   pair<ll,ll>
/// --------------------------------------------------------------------------------------------------------- ///
#define printv(v)             for(auto &i: v){cout << i << " ";} cout << endl;
#define printmap(mp)          for(auto &i: mp){cout << i.first << " "<<i.second<<endl;}
#define printset(st)          for(auto &i: st){cout << i << " ";} cout << endl;
#define line                  cout<<"----------------------------------------"<<endl;
#define arrow                 cout<<"--->";
#define debugmap(mp)             for(auto &i: mp){cout << i.ff << "-->" << i.ss <<endl;} cout << endl;
#define debugset(st)             for(auto &i: st){cout << i << " ";} cout << endl;
#define fast_io               ios_base::sync_with_stdio(false);cin.tie(NULL);
//#define endl                  " \n"
/// --------------------------------------------------------------------------------------------------------- ///

/// --------------------------------------------------------------------------------------------------------- ///
//reference for sequence(NT) --> oeis.org
//log2(x)
//give separate condition checks for smaller values of n(like n<=2)
//never use = sign in comparator functions
//the real challenge of bs --> selection of lo and hi
//set.lower_bound(x)
//for mod division --> a/b use a*inverse(b) (don't divide simply)
//set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
//gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
/// --------------------------------------------------------------------------------------------------------- ///



   
//floyd warshall
void shortest_distance(map<ll,map<ll,ll>> &dis){
	    ll n=dis.size();
	    for(ll val=0;val<n;++val)
	    {
	       for(ll i=0;i<n;++i)
	       {
	           for(ll j=0;j<n;++j)
	           {
	               dis[i][j]=min(dis[i][j],dis[i][val]+dis[val][j]);
	           }
	       }
	    }
}


void solve()
{
   inp(n);
   map<ll,map<ll,ll>> dis;

   fr(i,n){
    fr(j,n)
    cin>>dis[i][j];
   }
   //line
   vector<ll> edges(n);
   inpv(edges);
 
   vector<ll> sum;
   ll temp_sum=0;
 
   map<ll,map<ll,ll>> copp=dis;
   shortest_distance(dis);

   fr(i,n){
    fr(j,n){
        temp_sum+=dis[i][j];
    }
   }
 
   dis=copp;
   sum.pb(temp_sum);
 
   for(ll i=0;i<(n-1);++i){
        temp_sum=0;
        dis.erase(edges[i]-1);

        for(ll i=0;i<n;++i){
            dis[i][edges[i]-1]=-1;
        }
        shortest_distance(dis);
        for(ll k=0;k<(dis.size());++k){
            for(ll t=0;t<(dis.size());++t)
            temp_sum+=dis[k][t];
        }
        sum.pb(temp_sum);
 
   }
    printv(sum);
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
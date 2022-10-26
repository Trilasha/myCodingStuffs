/*
Trilasha Mazumder
2112063
*/

/// ------------------------------------HEADER-FILES and ABBREVIATIONS---------------------------- ///
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 


using namespace std;
using namespace __gnu_pbds;

typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; 


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
/// ------------------------------------PRE-DEFINED VALUES---------------------------------------- ///
#define maxval                1000000007
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
#define allasort(str)         sort(str.begin(), str.end())
#define alldsort(str)         sort(str.begin(), str.end(),greater<char>())
#define all(str)              str.begin(), str.end()
#define pll                   pair<ll,ll>


/// ------------------------------------NUMBER THEORY--------------------------------------------- ///
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
//vector<ll> v= sieve(1e5+10);
////TC--> nloglogn

/// ------------------------------------PRINTOUTS------------------------------------------------- ///
#define printv(v)             for(auto &i: v){cout << i << " ";} cout << endl;
#define printmap(mp)          for(auto &i: mp){cout << i.first << " "<<i.second<<endl;}

/// ---------------------------------------------------------------------------------------------- ///
//ceil(log2(x))
//is_sorted(all(v))
//is_sorted(s.begin(), s.end())
//string upp="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//string low="abcdefghijklmnopqrstuvwxyz";
//string num="0123456789";
/// ---------------------------------------------------------------------------------------------- ///
    



void solve(){
   inp(n);
   vector<ll> v(n);
   inpv(v);

   map<ll,ll> mp;
   pbds A;
   vector<ll> count;

   ll temp=0;

   fr(i,n)
   {
   mp[v[i]]++;
   A.insert(v[i]);
   }
   //
   for(auto &i:A)
   {
   temp+=mp[i];
   count.pb(temp);
   }
   inp(q);
   while(q--)
   {
    ll x;
    cin>>x;
    ll check=0;
    ll index=A.order_of_key(x);
    if(index<1)
    {
    if(mp[x]!=0)
    cout<<1<<endl;
    else
    cout<<0<<endl;
    }
    else
    cout<<count[index-1]+mp[x]<<endl;
   }
   }

   //tc-->qlogn

    
int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);

    
ll q;
//cin>>q;
q=1;
while(q--)
{
    solve();
}
    return 0;
}















/*
//////
string s=to_string(bitset<64> b(10));

////////
stack,queue->no index access
use deque,vectors
-->assign(n,val)available for both
-->take size +1(extra) for vectors


////////// working with iterators  //////////
auto it=upper_bound(all(v),i);
it--;
ll index=it-v.begin();


/////////////////////////////////////////////////////////// PBDS ////////////////////////////////////////////////////////
//for the 'less' one
//exactly functions like SET but with added benefits of-->count of the elements less than a particular value and indexing
//if written 'greater' instead of 'less'     --> values will be sorted in descending order then
//if written 'less_equal' instead of 'less'  --> works like MULTISET(duplicates will also exist then)

pbds A;
*A.find_by_order(x) -->returns the element present at the xth index
A.order_of_key(x)   -->returns the number of elements strictly lesser than x
A.erase(x)          -->if x is present then erases it from the ordered set

*******All the properties of SET like size(),begin(),end() can be used*******
1 2 7 8
*A.lower_bound(6) -->7
*A.lower_bound(2) -->2
*A.upper_bound(6) -->7
*A.upper_bound(2) -->7

printing the pbds -->similar to maps,sets and vectors
//all tc-->logn
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

*/

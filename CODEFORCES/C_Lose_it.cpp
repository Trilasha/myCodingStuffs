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
#define all(str)              str.begin(), str.end()
#define pll                   pair<ll,ll>


/// ------------------------------------NUMBER THEORY--------------------------------------------- ///
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
/*
vector<ll> v= sieve(1e5+10);
TC--> nloglogn
*/

/// ------------------------------------PRINTOUTS------------------------------------------------- ///
#define printv(v)             for(auto &i: v){cout << i << " ";} cout << endl;
#define printmap(mp)          for(auto &i: mp){cout << i.first << " "<<i.second<<endl;}
void google(ll t) {cout << "Case #" << t << ": ";}


void avoid_error()
{
/*
when the ans vector contains modulated values,then take the modulo(%) while calculating the elements' value...DON'T JUST PUT % AT THE TIME OF INSERTION 
CORRECT                     :-loop-->anss=(anss*powers[j])%(nn); then ans.pb(anss);
WRONG(tle,rte or wa)        :-loop-->anss=(anss*powers[j]); then ans.pb(anss%nn);
AVOID creating any prefix product array in case of modulo problems

-->take size +1(atleast extra) for vectors to avoid out of bounds

-->ll suma=accumulate(all(a),0LL);
//put OLL or else WA for larger sum
*/
}


    


void solve()
{
inp(n);
vector<ll> v(n);
inpv(v);

if(n<6)
{
cout<<n<<endl;
return;
}
map<ll,ll> mp;
fr(i,n)
mp[v[i]]++;

ll mini=INT_MAX;
for(auto &i:mp)
{
    mini=min(mini,i.second);
}
//cout<<mini<<endl;
vector<vector<ll>> vv(44);

fr(i,n)
{
    vv[v[i]].pb(i);
}
ll ok=0;
for(ll i=0;i<mini;++i)
{
    ll ind1=ub(all(vv[8]),vv[4][i])-vv[8].begin();
    if(ind1==vv[8].size())
    break;

    ll ind2=ub(all(vv[15]),vv[8][ind1])-vv[15].begin();
    if(ind2==vv[15].size())
    break;

    ll ind3=ub(all(vv[16]),vv[15][ind2])-vv[16].begin();
    if(ind3==vv[16].size())
    break;

    ll ind4=ub(all(vv[23]),vv[16][ind3])-vv[23].begin();
    if(ind4==vv[23].size())
    break;

    ll ind5=ub(all(vv[42]),vv[23][ind4])-vv[42].begin();
    if(ind5==vv[42].size())
    break;

    ok++;
     vv[8][ind1]=-1;
    vv[15][ind2]=-1;
    vv[16][ind3]=-1;
    vv[23][ind4]=-1;
    vv[42][ind5]=-1;
    
}


cout<<(n-6*ok)<<endl;
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
















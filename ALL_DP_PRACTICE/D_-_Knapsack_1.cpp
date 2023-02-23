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
#define md                    998244353
#define modval                  1000000007
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
void google(ll t)             {cout << "Case #" << t << ": ";}

/// ---------------------------------------------------------------------------------------------- ///





void solve()
{
    ll n,max_weight;
    cin>>n>>max_weight;

    vector<ll> wt(n),val(n);
    fr(i,n)
    cin>>wt[i]>>val[i];

    ll dp[n+1][max_weight+1];

    for(ll i=0;i<=max_weight;++i)
    dp[0][i]=0;
    
    for(ll i=0;i<=n;++i)
    dp[i][0]=0;

    for(ll i=1;i<=n;++i)
    {
        for(ll j=0;j<=max_weight;++j)
        {
            if(wt[i-1]<=j)
            dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            else
            dp[i][j]=dp[i-1][j];
        }
    }


    cout<<dp[n][max_weight]<<endl;
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


















/// ---------------------------------------------------------------------------------------------- ///
// v[i]=pow(10,v[i])+0.1; 
// max 1e7 size vector can be created
// vector<vector<int>> M;
// M.resize(m, vector<int>(n));
// binary_search(all(v),5)-->returns boolean value
// iota(all(v),10); -- > o/p--> 10 11 12 13 14 15 16 17 18 19
// a + b = a ^ b + 2 * (a & b)

// bitset<32> b(n);
// string s=b.to_string();
// b.to_ullong()
///------------------------------------------------------------------------------------------------///
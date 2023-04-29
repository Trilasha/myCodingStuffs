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

/// ------------------------------------NUMBER THEORY-------------------------------------------------------- ///
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll phi(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
ll bpow(ll base,ll power){ll res=1;while(power){if(power&1){res *= base;power--;}else{base *= base;power /=2;}}return res;}
ll expo(ll a, ll b, ll modd) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % modd; a = (a * a) % modd; b = b >> 1;} return res;}

/*
vector<ll> v= sieve(1e5+10);
TC--> nloglogn
*/

/// --------------------------------------------------------------------------------------------------------- ///
#define printv(v)             for(auto &i: v){cout << i << " ";} cout << endl;
#define printmap(mp)          for(auto &i: mp){cout << i.first << " "<<i.second<<endl;}
#define printset(st)          for(auto &i: st){cout << i << " ";} cout << endl;
#define line                  cout<<"----------------------------------------"<<endl;
#define arrow                 cout<<"--->";
#define debugmap(mp)             for(auto &i: mp){cout << i.ff << "-->" << i.ss <<endl;} cout << endl;
#define debugset(st)             for(auto &i: st){cout << i << " ";} cout << endl;
#define fast_io               ios_base::sync_with_stdio(false);cin.tie(NULL);

/// --------------------------------------------------------------------------------------------------------- ///
//reference for sequence(NT) --> oeis.org
//log2(x)
//give separate condition checks for smaller values of n(like n<=2)


map<ll,ll> mp;
void primefactors(ll n)
{
    if(n<=1) return;
    while(n%2==0)
    {
        mp[2]++;
        n=n/2;
    }
     while(n%3==0)
    {
        mp[3]++;
        n=n/3;
    }
    for (ll i = 5; i*i<=n; i=i+6)
    {
        while (n%i==0)
        {
            mp[i]++;
            n=n/i;
        }
        while(n%(i+2)==0)
        {
            mp[i+2]++;
            n=n/(i+2);
        }
    }
    if(n>3)
    mp[n]++;
    return;
}

void solve(){
    mp.clear();
    ll n;
    cin>>n;
    vector<ll> v(n);
    inpv(v);
    for(ll i=0;i<n;++i){
        primefactors(v[i]);
    }

    ll ans=0;
    for(auto &i:mp){
        if(i.ss%2==0){
            ans+=(i.ss)/2;
            mp[i.ff]=0;
        }
        else{
            ans+=(i.ss)/2;
            mp[i.ff]=1;
        }
    }

    ll cnt=0;
    for(auto &i:mp){
        cnt+=i.ss;
    }

    ans+=(cnt/3);
    cout<<ans<<endl;
}


int main(){

fast_io;

ll q=1;
cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}
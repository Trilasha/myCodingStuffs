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




void solve()
{
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    ll ct=0;

    if(n==1)
    {
        ct=(s[0]=='0')?1:0;
        cout<<ct<<endl;
        return;
    }

    vector<ll> one;
    for(ll i=0;i<n;++i)
    {
        if(s[i]=='1')
        one.pb(i);
    }

    if(one.size()==0)
    {
        ll temp=s.size()/(k+1);
        ll rem=s.size()%(k+1);
        if(rem==0)
        cout<<temp<<endl;
        else
        cout<<temp+1<<endl;

        return;
    }

    if(one[0]>k)
    {
        ct+=(one[0]/(k+1));
    }

    if((n-1)-one[one.size()-1]>k)
    {
        ct+=((n-1)-one[one.size()-1])/(k+1);
    }


    for(ll i=0;i<one.size()-1;++i)
    {
        ll a=one[i];
        ll b=one[i+1];
        ll diff=b-a-1;

        ll temp=diff/(k+1);
        ll rem=diff%(k+1);

        ct+=(rem==k)?temp:(temp-1);
    }


    cout<<max(ct,0ll)<<endl;

}
    
int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);
    
ll q=1;
cin>>q;
for(ll i=0;i<q;i++){
   // google(i+1);
    solve();
}
    return 0;
}



































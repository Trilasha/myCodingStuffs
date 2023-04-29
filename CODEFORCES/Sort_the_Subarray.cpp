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







void solve()
{
    ll n;
    cin>>n;
    vector<ll> a(n),b(n);
    inpv(a);
    inpv(b);

    pll p;
    ll mx=1;
    ll curr=1;
    ll k=1;
    ll j=-1;
    ll chk=0;
    ll ok=0;
    ll f=0;

    ll t=0;

    for(ll i=0;i<n-1;++i)
    {
        if(b[i+1]>=b[i])
        {
            if(b[i+1]!=a[i+1])
            ok=1;
            if(b[i]!=a[i])
            ok=1;

            curr++;
            if(chk==0)
            k=i+1;
            chk=1;
            t=1;
        }
        else if(ok==1 && b[i+1]<b[i])
        {
        j=i+1;
        break;
        }
        else if(t==1 && ok==0)
        {
            if(curr>mx)
            {
                mx=curr;
                p.ff=k;
                p.ss=i+1;
            }

                curr=1;
                k=i+2;
                chk=0;
                //ok=1;
                //f=1;
        }

        //cout<<j<<endl;
    }

    if(ok==1)
    {
        if(j==-1)
        j=n;
        p.ff=k;
        p.ss=j;
    }

    else if(curr>mx && ok==0)
    {
        p.ff=k;
        p.ss=n;
    }

    cout<<p.ff<<" "<<p.ss<<endl;
}


int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);

ll q=1;
cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}
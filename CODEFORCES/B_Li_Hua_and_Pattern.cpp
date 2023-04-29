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
//reference for sequence(NT) --> oeis.org




//https://codeforces.com/contest/1797/submission/201345408
void solve()
{
   ll n,k;
   cin>>n>>k;
   vector<vector<ll>> v(n,vector<ll>(n));
   fr(i,n)
   {
    fr(j,n)
    cin>>v[i][j];
   }

   vector<string> vv;
   fr(i,n)
   {
    string temp="";
    fr(j,n)
    {
        if(v[i][j]==0)
        temp.pb('0');
        else
        temp.pb('1');
    }
    vv.pb(temp);
   }

   //case1
   ll cnt=0;

   for(ll i=0;i<n/2;++i)
   {
    reverse(all(vv[n-i-1]));
    string a=vv[n-i-1];
    reverse(all(vv[n-i-1]));
    for(ll j=0;j<n;++j)
    {
        if(vv[i][j]!=a[j])
        cnt++;
    }
    //cout<<cnt<<endl;
   }


   //cout<<cnt<<endl;
   ll sp=0;
   ll tt=cnt;

   if(n%2)
   {
    ll ind=n/2;
    string temp=vv[ind];
    reverse(all(temp));
    fr(i,n)
    {
        if(temp[i]!=vv[ind][i])
        {
        sp++;
        }
    }
   }

   cnt=cnt+(sp/2);


   if(cnt==k)
   {
    cout<<"YES"<<endl;
    return;
   }

   if(cnt>k)
   {
   cout<<"NO"<<endl;
   return;
   }

   if(cnt<k)
   {
    //k=k-cnt;
    if(n%2==0)
    {
        /******** BUG *********
        // ll rem=(n*n)-(2*cnt);
        // if(rem>0)
        // {
        //     cout<<"YES"<<endl;
        //     return;
        // }
        */

        k=k-cnt;
        if(k%2==0)
        {
        cout<<"YES"<<endl;
        return;
        }
    }
    else if(n%2)
    {
        ll rem=(n*n)-(2*tt)-n;
        rem=rem+(n-(sp));
        if(rem>0)
        {
            cout<<"YES"<<endl;
            return;
        }

        k=k-tt;
        k=k-(sp/2);

        if(k%2==0)
        {
        cout<<"YES"<<endl;
        return;
        }
    }
   }

   cout<<"NO"<<endl;





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

















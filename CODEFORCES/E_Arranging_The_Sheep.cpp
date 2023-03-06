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
//int m = number of rows, n = number of columns;
//M.resize(m, vector<int>(n));
//binary_search(all(v),5)-->returns boolean value




//0 2 6 8 9
void solve()
{
    inp(n);
    string s;
    cin>>s;

    ll cnt=count(all(s),'*');

    ll ind,ind1,ind2;
    ll ans=0;
    ll temp=0;

    if(cnt==0)
    cout<<ans<<endl;

    else if(cnt%2)
    {
        vector<ll> store;
        ll var=cnt/2;
        fr(i,n)
        {
            if(s[i]=='*')
            {
            temp++;
            store.pb(i);
            }
            if(temp==(var+1))
            {
                ind=i;
            }
        }

        ll base=ind;
        for(ll i=var-1;i>=0;--i)
        {
            ans+=base-store[i]-1;
            base--;
        }
        base=ind;
        for(ll i=var+1;i<store.size();++i)
        {
            ans+=store[i]-base-1;
            base++;
        }
        cout<<ans<<endl;

    }
    else
    {
        ind1=cnt/2-1;
        ind2=ind1+1;
        ll ans1=0;
        ll ans2=0;

        ll base1;
        ll base2;

        vector<ll> store;
        fr(i,n)
        {
            if(s[i]=='*')
            {
            temp++;
            store.pb(i);
            }
            if(temp==(ind1+1) && s[i]=='*')
            base1=i;
            else if(temp==(ind2+1) && s[i]=='*')
            base2=i;
        }

       // cout<<base1<<" "<<base2<<endl;
        ll ori=base1;
        for(ll i=ind1-1;i>=0;--i)
        {
            ans1+=base1-store[i]-1;
            base1--;
        }
        base1=ori;
       // cout<<base1<<endl;
        for(ll i=ind1+1;i<store.size();++i)
        {
            ans1+=store[i]-base1-1;
            base1++;
        }

       // cout<<ans1<<endl;
        //
        ori=base2;
        for(ll i=ind2-1;i>=0;--i)
        {
            ans2+=base2-store[i]-1;
            base2--;
        }
        base2=ori;
        for(ll i=ind2+1;i<store.size();++i)
        {
            ans2+=store[i]-base2-1;
            base2++;
        }
        cout<<min(ans1,ans2)<<endl;

    }


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


































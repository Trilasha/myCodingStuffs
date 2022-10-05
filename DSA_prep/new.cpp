/// ------------------------------------------------------------------------------------------------- ///
///////// SUCCESS IS NOT FINAL,FAILURE IS NOT FATAL. IT IS THE COURAGE TO CONTINUE THAT COUNTS //////////
/// ------------------------------------------------------------------------------------------------- ///
    
    
/// ------------------------------------HEADER-FILES and ABBREVIATIONS---------------------------- ///
#include <bits/stdc++.h>
using namespace std;
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
/// ------------------------------------FUNCTIONS 1.0---------------------------------------- ///

bool isPrime(ll n)
{
 if(n==1) return false;
if(n==2 || n==3) return true;
if(n%2==0 || n%3==0) return false;
for(ll i=5;i*i<=n;i=i+6)
if(n%i==0 || n%(i+2)==0)
return false;
return true;
}

///////
void divisors(ll n)
{
for (ll i = 1; i*i <=n; i++)
{
if(n%i==0)
{
cout<<i<<" ";
if(i!=n/i)
cout<<n/i<<" ";
}
}
}

///////
ll lcm(ll a,ll b)
{
    return (a*b)/__gcd(a,b);
}

///////
void printprimefactors(ll n)
{
    if(n<=1) return;
    while(n%2==0)
    {
        cout<<2;
        n=n/2;
    }
     while(n%3==0)
    {
        cout<<3;
        n=n/3;
    }
    for (ll i = 5; i*i<=n; i=i+6)
    {
        while (n%i==0)
        {
            cout<<i;
            n=n/i;
        }
        while(n%(i+2)==0)
        {
            cout<<i+2;
            n=n/(i+2);
        }
    }
    if(n>3)
    cout<<n;
    return;
    //i/p-->450
    //o/p-->23355
}

///////
ll binarysearch(ll arr[],ll n,ll key)
{
    ll lo=0,hi=n-1;
    ll mid;
    while(lo<=hi)
    {
        mid=lo+(hi-lo)/2;
        if(arr[mid]<key)
        lo=mid+1;
        else if(arr[mid]>key)
        hi=mid-1;
        else
        return mid;
    }
    return -1;
}

///////
ll ternary_search(ll l,ll r,ll x,ll ar[])
{
    if(r>=l)
    {
        ll mid1 = l + (r-l)/3;
        ll mid2 = r -  (r-l)/3;
        if(ar[mid1] == x)
            return mid1;
        if(ar[mid2] == x)
            return mid2;
        if(x<ar[mid1])
            return ternary_search(l,mid1-1,x,ar);
        else if(x>ar[mid2])
            return ternary_search(mid2+1,r,x,ar);
        else
            return ternary_search(mid1+1,mid2-1,x,ar);

    }
    return -1;
}

/// ------------------------------------FUNCTIONS 2.0---------------------------------------- ///
void printvector(vector<ll> &v)
{
    fr(i,v.size())
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

///////
void printarray(ll arr[],ll n)
{
    fr(i,n)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

///////

    
    

void solve()
{
    ll n;
    cin>>n;
    cout<<n<<endl;
}
    
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    
ll q;
cin>>q;
while(q--)
{
    solve();
}
    return 0;
}
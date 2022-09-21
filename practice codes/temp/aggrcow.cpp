#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define md                  10000007
#define fr(i,n)             for (ll i=0;i<n;++i)
#define inp(n)              ll n;cin>>n;
#define fr1(i,k,n)            for(ll i=k;i<n;++i)
#define inpv(v)              for(auto &x: v) cin>>x;
#define dsort(arr)            sort(arr,arr+n,greater<ll>())
#define asort(arr)            sort(arr,arr+n)
#define allasort(str)             sort(str.begin(), str.end())
#define alldsort(str)              sort(str.begin(), str.end(),greater<char>())
#define all            str.begin(), str.end()
#define lb lower_bound
#define up upper_bound
/*
inp(n);
vector<ll> v(n);
inpv(v);
for(auto &it:v)
cout<<it<<;
*/
    
/*bool isPrime(ll n)
{
 if(n==1) return false;
if(n==2 || n==3) return true;
if(n%2==0 || n%3==0) return false;
for(ll i=5;i*i<=n;i=i+6)
if(n%i==0 || n%(i+2)==0)
return false;
return true;
}
*/
/*void divisors(ll n)
{
for (ll i = 1; i*i <=n; i++)
{
if(n%i==0)
{
cout<<i;
if(i!=n/i)
cout<<n/i;
}
}
}*/
/*bool bit=!(n&(n-1));
return n && bit;*/
    
    
    
using namespace std;
const ll N=1e5+10;
//N=1e9+10 throws error 
//hi=1e9 only accepted
ll arr[N];
bool check(ll mid,ll n,ll cows)
{
    ll c=-1;
    //not assigned any position yet so let it be -1
for (ll i = 0; i < n; i++)
{
    if(arr[i]-c>=mid || c==-1)
    {
        c=arr[i];
        cows--;
    }
    if(cows==0)
    break;
}
return (cows==0);
}
void solve()
{
    ll n,cows;
    cin>>n>>cows;
    fr(i,n)
    cin>>arr[i];
    asort(arr);
    ll lo=0,hi=1e9;
    ll mid;
    while (hi-lo>1)
    {
        mid=(lo+hi)/2;
        if(check(mid,n,cows))
        lo=mid;
        else
        hi=mid-1;
    }
    if(check(hi,n,cows))
    cout<<hi<<endl;
    else
    cout<<lo<<endl;
    
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
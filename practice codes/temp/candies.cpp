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
void solve()
{
    inp(n);
    ll sum_e=0;
        ll sum_o=0;
        ll e=2;
        ll ori=1;
        ll o=1;
        ll check=0;
        ll arr[n];
    
    if(n==2)    
    {
        cout<<"NO"<<endl;
        return;
    }
    else
    {
        
        for (ll i = 0; i <(n/2); ++i)
        {
            sum_e+=e;
            e+=2;
        } 
        for (ll i = 0; i <(n/2)-1; ++i)
        {
            arr[i]=o;
            sum_o+=o;
            o+=2;
        }
        arr[n/2-1]=sum_e-sum_o;
        if(arr[n/2-1]>0 && arr[n/2-1]%2!=0)
        {
        cout<<"YES"<<endl;
         ll ev=2;
        for (ll i = 0; i < n/2; ++i)
        {
            cout<<ev<<" ";
            ev+=2;
        }
        for (ll i = 0; i < n/2; ++i)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }
   else
        {
            cout<<"NO"<<endl;
            return;
        }
    }
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
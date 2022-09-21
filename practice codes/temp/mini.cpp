/*Name     -->Trilasha Mazumder
ScholarID  -->2112063*/
/// ------------------------------------HEADER-FILES and ABBREVIATIONS---------------------------- ///
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define popb pop_back
#define lb lower_bound
#define up upper_bound
#define umap          unordered_map
#define uset          unordered_set
/// ------------------------------------PRE-DEFINED VALUES---------------------------------------- ///
#define md                  10000007
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
vector<ll> v(n);
set<ll> s;
inpv(v);
sort(v.begin(),v.end());
ll index=0;
if(n==3)
{
    cout<<"NO"<<endl;
    return;
}
for (ll i = 0; i < n; ++i)
{
    if(i==n-1)
    break;
    if(v[i]<v[i+1] && i+1==n-1)
    break;
    if(v[i]<v[i+1] && v[i+2]==v[i+1])
{
    cout<<"NO"<<endl;
    return;
}
    if(v[i]<v[i+1] && v[i+2]>v[i+1])
    {
            swap(v[i+1],v[i+2]);
            i++;
    }
    else if(v[i]==v[i+1])
    {
        vector<ll>:: iterator upper1;
        upper1=up(v.begin(),v.end(),v[i+1]);
        index=upper1-v.begin();
        if(upper1!=v.end())
        {
            if(s.find(i+1)==s.end())
            {
                swap(v[i+1],v[index]);
                s.insert(i+1);
            }
            else
            {
                cout<<"NO"<<endl;
                return;
            }
        }
        else
        {
            cout<<"NO"<<endl;
            return;
        }
        
    }
}
cout<<"YES"<<endl;
for(auto &i:v)
{
    cout<<i<<" ";
}
cout<<endl;
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
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
// bool check(ll arr1[],ll arr2[],ll arr1_sort[],ll arr2_sort[],ll n)
// {
//     fr(i,n)
//     {
//         if(arr1[i]!=arr1_sort[i] || arr2[i]!=arr2_sort[i])
//         return false;
//     }
//     return true;
// }
void solve()
{
    inp(n);
make(arr1,n);
make(arr2,n);
ll arr1_sort[n],arr2_sort[n];
fr(i,n)
{
    arr1_sort[i]=arr1[i];
    arr2_sort[i]=arr2[i];
}
asort(arr1_sort);
asort(arr2_sort);
vector<pair<ll,ll>> v;
ll k=0;
fr(i,n)
{
    for (ll j = i; j < n; ++j)
    {
        if(arr1[i]>arr1[j] || arr2[i]>arr2[j])
        {
            swap(arr1[i],arr1[j]);
            swap(arr2[i],arr2[j]);
            if(arr1[i]>arr1[j] || arr2[i]>arr2[j])
            {
                cout<<-1<<endl;
                return;
            }
            else
            {
                k++;
                v.pb(make_pair(i+1,j+1));
            }
        }
    }
    
}
//if(check(arr1,arr2,arr1_sort,arr2_sort,n))
//{
    cout<<k<<endl;
    for(auto &i:v)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    return;
//}
// else
// {
//     cout<<-1<<endl;
//     return;
// }
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
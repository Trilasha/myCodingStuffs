/// ------------------------------------------------------------------------------------------------- ///
///////// SUCCESS IS NOT FINAL,FAILURE IS NOT FATAL. IT IS THE COURAGE TO CONTINUE THAT COUNTS //////////
/// ------------------------------------------------------------------------------------------------- ///
    
    
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
{ for (ll i = 1; i*i <=n; i++)
{if(n%i==0)
{cout<<i;
if(i!=n/i)
cout<<n/i;
}}}*/
/*bool bit=!(n&(n-1));
return n && bit;*/
    
    
    
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    vector<ll> v={1,2,3,4,5,6,7,8,9};
//rotate(v.begin(),v.begin()+3,v.end());
//o/p-->4 5 6 7 1 2 3 

//rotate(v.begin(),v.begin()+v.size()-3,v.end());
//o/p-->7 8 9 1 2 3 4 5 6 


//rotate(v.begin(),v.begin()+3,v.begin()+6);
//rotate(starting index of the range,which element to be first,the ending index range+1)
//o/p-->4 5 6 1 2 3 7 8 9

rotate(v.begin()+2,v.begin()+3,v.begin()+6);
//o/p-->1 2 4 5 6 3 7 8 9 


for(auto &i:v)
cout<<i<<" ";
    return 0;
}
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
#define make(arr,n)   ll arr[n]; f(i,n) cin>>arr[i];
/// ------------------------------------FOR LOOPS AND SORT---------------------------------------- ///
#define fr(i,n)             for (ll i=0;i<n;++i)
#define fA(i,a,n)   for(ll i=a;i<=(n);++i)
#define fD(i,a,n)   for(ll i=a;i>=(n);--i)
#define dsort(arr)            sort(arr,arr+n,greater<ll>())
#define asort(arr)            sort(arr,arr+n)
#define allasort(str)             sort(str.begin(), str.end())
#define alldsort(str)              sort(str.begin(), str.end(),greater<char>())
#define all            str.begin(), str.end()
/// ------------------------------------OTHERS--------------------------------------------------- ///
#define ub(a,x)     upper_bound(all(a), x)
#define ps(x,n)     fixed<<setprecision(n)<<x
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
  //  map<ll,ll> mp;
  //  multimap<ll,ll> mp;
  unordered_map<ll,ll> mp;
 // set<ll> s;
 // multiset<ll> s;
 //unordered_set<ll> s;
    for (ll i = 0; i < 7; i++)
    {
       inp(n);
     //  s.insert(n);
       mp[n]++;
    }
      for(auto &it:mp)  
      {
          cout<<it.first<<" "<<it.second<<endl;
      }
    // for(auto &it:s)
    // cout<<it<<endl;
    // return 0;
}
/*i/p
4
2
7
7
1
1
1

//when map is used
o/p
1 3
2 1
4 1
7 2

//when unordered_map is used
1 3
4 1
7 2
2 1


///when multimap used
prog.cpp: In function ‘int main()’:
prog.cpp:70:10: error: no match for ‘operator[]’ (operand types are ‘std::multimap<long long int, long long int>’ and ‘long long int’)
   70 |        mp[n]++;


//when set is used
1
2
4
7

//when multiset is used
1
1
1
2
4
7
7

//when unordered_set is used
1
4
7
2

*/
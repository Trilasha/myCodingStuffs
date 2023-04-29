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
bool comp(pair<int, char> p1, pair<int, char> p2){
   if (p1.first != p2.first) return p1.first > p2.first; 
   else {
     return p1.second < p2.second; 
   }
}
void solve(){
   map<char,ll> m;
   string s;
   cin >> s;
   ll n = s.length();
   for(int i =0; i < n ; ++i){
      m[s[i]]++;
   }
   vector<pair<int , char> > v;
   for(auto i:m){
      v.pb(make_pair(i.second,i.first));
   }
   sort(v.begin(),v.end(), comp);
   for(auto i:v){
      for(int j = 0 ; j < i.first ; ++j){
         cout << i.second << "";
      }
   }

}
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// int test=1; cin >> test; 
	// while (test--) {
		solve();
	// }
  return 0; 
}
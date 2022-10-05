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
    


using namespace std;
void solve(string ip,string op)
{
  if(ip.length()==0)
  {
      cout<<op<<endl;
      return;
  }
  string op1=op;
  string op2=op;
  op1.pb(' ');
  op1.pb(ip[0]);
  op2.pb(ip[0]);
  ip.erase(ip.begin()+0);
  solve(ip,op1);
  solve(ip,op2);
  return;
}
    
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    
string ip;
cin>>ip;
string op="";
op.pb(ip[0]);
ip.erase(ip.begin()+0);
solve(ip,op);
    return 0;
}

/*
////  INPUT  ////
abc
////  OUTPUT  ////
a b c
a bc
ab c
abc
*/



//////////////////////////////////////////  MY SELF WRITTEN CODE ////////////////////////////////////////
/*
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
    


using namespace std;
void solve(string ip,string op,ll n)
{
  if(ip.length()==0)
  {
      cout<<op<<endl;
      return;
  }
  string op1=op;
  string op2=op;
  op1.pb(ip[0]);
  op2.pb(' ');
  op2.pb(ip[0]);
  ip.erase(ip.begin()+0);
  if(ip.length()==n-1)
  solve(ip,op1,n);
  else
  {
       solve(ip,op1,n);
        solve(ip,op2,n);
  }
  return;
}
    
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    
string ip;
cin>>ip;
string op="";
int n=ip.size();
solve(ip,op,n);
    return 0;
}



////  INPUT  ////
abc
////  OUTPUT  ////
abc
ab c
a bc
a b c

*/
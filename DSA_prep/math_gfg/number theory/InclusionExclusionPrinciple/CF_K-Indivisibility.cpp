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
    
/*
i/e principle-->
when odd numbered pair= minus
when even numbered pair=add
*/    
 //////////////////////// not divisible by any number from 2 to 10 /////////////////////

using namespace std;
void solve()
{
    inp(n);
    //2 3 5 7
    //4combo
    ll one=n/2 +n/3+n/5+n/7;
    //6 combo
    ll two=n/(2*3)+n/(2*5)+n/(2*7)+n/(3*5)+n/(3*7)+n/(5*7);
    //4 combo
    ll three=n/(2*3*5)+n/(3*5*7)+n/(2*5*7)+n/(2*3*7);
    //1 combo
    ll four=n/(2*3*5*7);
    cout<<n-one+two-three+four<<endl;
}
    
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    
ll q;
//cin>>q;
q=1;
while(q--)
{
    solve();
}
    return 0;
}
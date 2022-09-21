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
void solve()
{
    inp(n);
    make(arra,n);
    ll arrd[n];
    fr(i,n)
    arrd[i]=1000-arra[i];
    vector<ll> attack;
    vector<ll> defence;
    fr(i,n)
    {
        if(arra[i]>=arrd[i])
        {
            attack.pb(arra[i]);
        }
        else
        defence.pb(arrd[i]);
    }
    if(attack.size()==0)
    {
        sort(defence.begin(),defence.end());
        attack.pb(1000-defence[0]);
        defence.erase(defence.begin());

    }
    else if(defence.size()==0)
    {
        sort(attack.begin(),attack.end());
        defence.pb(1000-attack[0]);
        attack.erase(attack.begin());

    }
     ll suma=accumulate(attack.begin(),attack.end(),0);
     ll sumd=accumulate(defence.begin(),defence.end(),0);
    //  if(suma==0 && sumd!=0)
    //  cout<<sumd<<endl;
    //  else if(suma!=0 && sumd==0)
    //  cout<<suma<<endl;
    //  else
     cout<<suma*sumd<<endl;
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
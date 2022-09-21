#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define md                  10000007
#define fr(i,n)             for (ll i=0;i<n;++i)
#define fr1(i,k,n)            for(ll i=k;i<n;++i)
#define dsort(arr)            sort(arr,arr+n,greater<ll>())
#define asort(arr)            sort(arr,arr+n)
#define allasort(str)             sort(str.begin(), str.end())
#define alldsort(str)              sort(str.begin(), str.end(),greater<char>())
#define all            str.begin(), str.end()
#define lb lower_bound
#define up upper_bound
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    ll q;
    cin>>q;
while (q--)
{
   ll n;
   cin>>n;
   ll arr[n];
   fr(i,n)
   cin>>arr[i];
   if(n%2==0)
   {
       ll suml=0;sumr=0;
       for (ll i = 0; i <n/2; i++)
       {
          suml+=arr[i];
          for (ll j = n-1; j >=n/2; ++j)
          {
              sumr+=arr[j];
              if(suml)
          }
          
       }
       
   }
}
    
    return 0;
}
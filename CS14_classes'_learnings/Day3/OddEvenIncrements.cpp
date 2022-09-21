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
ll const N=57;
ll arr[N];
bool check1(ll arr[],ll n)
{
for (ll i = 1; i <=n; i=i+2)
{
    if(arr[i]%2!=0)
    return  false;
}
return true;
}
bool check4(ll arr[],ll n)
{
for (ll i = 1; i <=n; i=i+2)
{
    if(arr[i]%2==0)
    return  false;
}
return true;
}

bool check2(ll arr[],ll n)
{
    for (ll i = 2; i <=n; i=i+2)
    {
       if(arr[i]%2!=0)
       return false;
    }
    return true;
}
bool check3(ll arr[],ll n)
{
    for (ll i = 2; i <=n; i=i+2)
    {
       if(arr[i]%2==0)
       return false;
    }
    return true;
}
bool check5(ll arr[],ll n)
{
    for (ll i = 2; i <=n; i=i+2)
    {
       if(arr[i]%2!=0)
       return false;
    }
    return true;
}
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
  for (ll i = 1; i <=n; ++i)
  {
      cin>>arr[i];
  }
  if(arr[1]%2==0)
  {
      if(check1(arr,n)==0)
      {
          cout<<"NO"<<endl;
      }
      else
      {
          if(arr[2]%2==0)
          {
              if(check2(arr,n)==0)
              {
                  cout<<"NO"<<endl;
              }
              else
              cout<<"YES"<<endl;
          }
          else if(arr[2]%2!=0)
          {
              if(check3(arr,n)==0)
              cout<<"NO"<<endl;
              else
              cout<<"YES"<<endl;
          }
      }
      
  }
  else if(arr[1]%2!=0)
  {
      if(check4(arr,n)==0)
      {
          cout<<"NO"<<endl;
      }
      else
      {
          if(arr[2]%2==0)
          {
              if(check5(arr,n)==0)
              {
                  cout<<"NO"<<endl;
              }
              else
              cout<<"YES"<<endl;
          }
          else if(arr[2]%2!=0)
          {
              if(check3(arr,n)==0)
              cout<<"NO"<<endl;
              else
              cout<<"YES"<<endl;
          }
      }
      
  }
}
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define md                  10000007
#define fr(i,n)             for (ll i=0;i<n;++i)
#define inp(n)              ll n;cin>>n;
#define fr1(i,k,n)            for(ll i=k;i<n;++i)
#define inpv(v)              for(auto &x: v) cin>>x;
#define dsort(arr)            sort(arr,arr+n,greater<ll>())
#define asort(arr)            sort(arr,arr+n)
#define allasort(str)             sort(str.begin(), str.end())
#define alldsort(str)              sort(str.begin(), str.end(),greater<char>())
#define all            str.begin(), str.end()
#define lb lower_bound
#define up upper_bound

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
ll n,total;
cin>>n>>total;
ll count=0;
ll var=0;
vector<ll> v(total);
ll index=0;
ll cat=0;
for (ll i = 0; i < total; i++)
{
    ll x;
    cin>>x;
    v[i]=n-x;
}
sort(v.begin(),v.end());
while (total>0)
{
    var++;
    if(var==v[index])
    {
        count++;
        index++;
        var=0;
        total--;
       for(auto i=v.begin();i!=v.end();i++)
      {
          if(i==var)
          {
              v.erase(i);
              break;
          }
      }
    }
    cat++;
    if(find(v.begin(),v.end(),(n-cat))!=v.end())
    {
        // for (ll i = 0; i < v.size(); i++)
        // {
        //     if(v[i]==(n-cat))
        //     {
        //     v.erase(v[i]);
        //     total--;
        //     }
        // }
         for(auto i=v.begin();i!=v.end();i++)
      {
          if(i==(n-cat))
          {
              v.erase(i);
              total--;
          }
      }
    }

}
cout<<count<<endl;
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
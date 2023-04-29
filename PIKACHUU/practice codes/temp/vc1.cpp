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
    ll n;
    cin>>n;
    vector<ll> v(n);
    inpv(v);
ll m;
cin>>m;
vector<ll> v2(m);
for (ll i = 0; i < m; i++)
{
    cin>>v2[i];
}
vector<ll> vc(n);
vector<ll> v2c(m);
for (ll i = 0; i < n; i++)
{
    vc.pb(v[i]);
}
for (ll i = 0; i < m; i++)
{
    v2c.pb(v2[i]);
}

sort(v.begin(),v.end());
sort(v2.begin(),v2.end());
sort(vc.begin(),vc.end());
sort(v2c.begin(),v2c.end());
ll ct=0;
ll res1=0;
while(1)
{
if(ct==0 && v[v.size()-1]>res1)
{
    res1=v[v.size()-1];
    ct=1;
    v.pop_back();
}
  if(ct==1 && v2[v2.size()-1]<=res1 || (v2.size()==0))
    {
        cout<<"Alice"<<endl;
        break;
    }

 if(ct==1 && v2[v2.size()-1]>res1)
{
    res1=v2[v2.size()-1];
    ct=0;
    v2.pop_back();
}
  if((ct==0 && v[v.size()-1]<=res1) || (v.size()==0))
    {
        cout<<"Bob"<<endl;
        break;
    }
  
}
ll kt=1;
ll res2=0;
while(1)
{
   
if(kt==0 && vc[vc.size()-1]>res2)
{
    res2=vc[vc.size()-1];
    kt=1;
    vc.pop_back();
}
  if(kt==1 && v2c[v2c.size()-1]<=res2 || (v2c.size()==0))
    {
        cout<<"Alice"<<endl;
        break;
    }
 if(kt==1 && v2c[v2c.size()-1]>res2)
{
    res2=v2c[v2c.size()-1];
    kt=0;
    v2c.pop_back();
}
 if(kt==0 && vc[vc.size()-1]<=res2 || (vc.size()==0))
    {
        cout<<"Bob"<<endl;
        break;
    }
    
}
// vector<ll> a;
// vector<ll> b;
// ll ct=0;
// while (true)
// {
//     if(ct==0)
//     {
//         s.pb(v[v.size()-1]);
//         v.pob_back();
//         ct=1;
//     }
//     else if()
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
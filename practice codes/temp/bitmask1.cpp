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
ll getFirstSetBitPos(ll n)
{
    return log2(n & -n) + 1;
}
void solve()
{
    inp(n);
    if(n==1)    
    cout<<3<<endl;
    else if((n&(n-1))==0)
    cout<<n+1<<endl;
    else
    {
        ll pos=getFirstSetBitPos(n)-1;
        cout<<(1<<pos)<<endl;
    }
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
/*
///another way
//To find the position of the first set bit(from right most)
 ll ct = 0, a = 0;
        while((n & (1<<a)) == 0){
            ct++;
            a++;
        }
//ct th position(considering 0 based indexing)

----------------------------------------------------------------------
//Techphile's code

  int solve( ){ 
            int n;cin>>n;
            if(n==1)return 3;
            int ans=0;
            int set=0,unset=0,k=1;
            while(set==0){
              if(n%2){
                  set=1;ans+=k;
                  
              }
              // else if(!unset){
              //   unset=1;ans+=k;
              // }
              k*=2;n/=2;
            }
if(n)return ans;
          
        return ans+1;
*/
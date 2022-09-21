
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PI 3.14159265
#define pb push_back
#define en cout<<'\n'
#define vec vector<ll>
#define vecs vector<string>
#define pii pair<ll,ll>
#define VP vector< pii >
#define all(v) (v).begin(),(v).end()
#define ff first
#define ss second
#define mm " "
#define MM " "
#define f(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define fa(x,v) for(auto x:v)
#define INF (ll)(9e18)
#define Sort(v) sort(v.begin(),v.end())
#define test ll T;cin>>T;while(T--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define max4(a,b,c,d) max(a,max3(b,c,d))
#define min4(a,b,c,d) min(a,min3(b,c,d))
#define lb(v,val)  (lower_bound(v.begin(),v.end(),val)-v.begin())
#define ub(v,val)  (upper_bound(v.begin(),v.end(),val)-v.begin())
 const ll MOD=1000000000+7;
const ll MOD1 = 998244353;
string itos(ll s)
{
string str=to_string(s);
return str;
}
ll stoi2(string s)
{
    ll a= atoi(s.c_str());
    return a;
}
ll powerm(ll a, ll b, ll MOD) {
    a %= MOD;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll power(ll a, ll b) {
   
  ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a ;
        a = a * a ;
        b >>= 1;
    }
    return res;
}

bool isSubSequence(string str1, string str2, int m, int n)
{

    if (m == 0) return true;
    if (n == 0) return false;

    if (str1[m-1] == str2[n-1])
        return isSubSequence(str1, str2, m-1, n-1);

    return isSubSequence(str1, str2, m, n-1);
}


bool ispalindrome(ll len,string str)
{
 
    for(int i = 0; i < len/2; i++){
        if(str[i] != str[len-1-i]){
            return false;
        }
    }
    return true;
}
ll binarySearch(ll a[],ll low,ll high,ll key){
    while(low<=high)
    {
        ll mid=(low+high)/2;
        if(a[mid]<key)
        {
            low=mid+1;
        }
        else if(a[mid]>key)
        {
            high=mid-1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
ll isprime(ll N){
    if(N<2 || (!(N&1) && N!=2))
        return 0;
    for(ll i=3; i*i<=N; i+=2){
        if(!(N%i))
            return 0;
    }
    return 1;
}
vec factor;
void factors(ll n)
{
    
for(ll i=1;i<=sqrt(n);i++)
{
    if(n%i==0)
    {
        if(i==n/i)
        factor.pb(i);
        else
        {
            factor.pb(i);
            factor.pb(n/i);
        }
        
    }
}
 
sort(all(factor));
}
ll gcd(ll a, ll b) { 
   if (b == 0) 	
      return a; 
   return gcd(b, a % b);  
}
ll lcm(ll a,ll b)
{
	return (a/gcd(a,b))*b;
}
bool isvalid(ll i,ll j,ll n)
{
    if(i>=0&&i<n&&j>=0&&j<n)return true;
    return false;
}
ll dx[8]={0,1,1,1,0,-1,-1,-1};
ll dy[8]={-1,-1,0,1,1,1,0,-1};


ll binarytodecimal(string n)
{
    string num = n;
    ll dec_value = 0;
 
   ll base = 1;
 
   ll len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}

string dtb(ll  n )
{
//    ,ll siz
    string s="";

    while(n>0){

    if(n%2==0)s.pb('0');
    else s.pb('1');
    n/=2;

    }

    reverse(all(s));
//       while(s.size()<siz)
//    {
//
//        s='0'+s;
//
//    }
    return s;
}

vec seive;
void Seive() {
    const ll maxn = 1e6 + 5;
    seive.resize(maxn);
    f(i,0, maxn) seive[i] = i;
    for(ll i=2;i<=maxn;i+=2)
    seive[i] = 2;
    seive[1] = -1;
    seive[0] = -1;
    for (ll i = 3; i <= maxn; i += 2)
        if (i == seive[i])
        for (ll j = i * i ; j < maxn ; j += i)
        if (seive[j] == j)
        seive[j] = i;
}



int main()
{
fast;


ll n;
cin>>n;
ll a[n+1];
f(i,0,n)cin>>a[i];
a[n]=5;
VP v;
ll k=a[0],c=1;
f(i,1,n+1)
{
    
    if(k!=a[i]){v.pb({k,c});c=1;k=a[i];}
    else 
    {
        c++;
    }
    
    
    
    
}
ll mx=0;
f(i,0,v.size()-1)
{
    mx=max(min(v[i].ss,v[i+1].ss),mx);
    
    
}
cout<<2*mx;












    
}
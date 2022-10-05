#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
//
using namespace std;
//
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
//
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
//
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
//
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
//
#define FOR(i, a, b) for (ll i=a; i<(b); i++)
#define F0R(i, a) for (ll i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define sumv(x)  accumulate((x).begin(), (x).end(), 1LL*0);
#define yes cout << "YES" << endl
#define no cout<<"NO"<<endl;
#define in(x) ll x; cin >> x;
#define inv(v,n) in(n);vl v(n);FOR(i, 0 , n) cin >> v[i];
//
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
//
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
//
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
//
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << "}\n";}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif
//
const ll MOD = 1e9 + 7;
const ll mod = 998244353;
const char nl = '\n';
const int MX = 100001;
//

ll power(ll n, ll r){
   if (r == 0) return 1;
   ll x = power(n, r/2);
   if(r%2 == 0){
      return ( (x) * (x) );
   }
   else {
      ll z = ((n) * (x));
      z = ( (z) * (x) );
      return z;
   }
}
ll sq_root(ll n){
   ll l = 0, r = n;
   while(l < r){
      ll m = (l + r) / 2;
      if(m * m <= n) l = m + 1;
      else r = m;
   }
   return l - 1;
}
const ll c = 1e6+9;
bool prime[c + 1] ;
void SieveOfEratosthenes(){
   memset(prime, true, sizeof(prime));
   prime[0] = false; prime[1] = false;
   for (int p = 2; p * p <= c; p++) {
      if (prime[p] == true) {
         for (int i = p * p; i <= c; i += p)
            prime[i] = false;
      }
   }
}
bool isprime(ll n){
   if(n<2){
      return false;
   }
   for(int i = 2; i*i<=n; i++){
      if(n%i == 0){
         return false;
      }
   }
   return true;
}
bool is_pelindrome(string s){
   int n = s.length();
   for(int i = 0; i < n/2; i++){
      if(s[i] != s[n-i-1]){
         return false;
      }
   }
   return true;
}
void print_arr(ll arr[], ll n){
   for(ll i = 0; i < n; i++){
	  cout << arr[i] << " ";
   }
   cout << endl;
}
void print_vec(vector<ll>&v){
   for(auto i:v){
      cout << i << " ";
   }
   cout << endl;
}
vector<ll> prime_factor(ll n){
   vector<ll>v;
   for(int i=2;i*i<=n;i++){
      while(n%i==0){
         v.pb(i);
         n/=i;
      }
   }
   if(n>1){
      v.pb(n);
   }
   return v;

}
void print_queue(queue<ll>&q){
   while(!q.empty()){
      cout << q.front() << " ";
      q.pop();
   }
   cout << endl;
}
void print_2D_vector(vector<vector<ll>>&v){
   for(auto i:v){
      for(auto j:i){
         cout << j << " ";
      }
      cout << endl;
   }
}
bool isPowerofTwo(long long n){
    if (n == 0)
        return 0;
    if ((n & (~(n - 1))) == n)
        return 1;
    return 0;
}
void print_number_of_divisior(ll n){
   ll cnt = 0;
   for(int i = 1; i <= sqrt(n); i++){
      if(n%i == 0){
         if(i*i == n){
            cnt++;
         }
         else{
            cnt+=2;
         }
      }
   }
   cout << cnt << endl;
}
bool ispalindrome(vector<ll>&v){
   int n = v.size();
   for(int i = 0; i < n/2; i++){
      if(v[i] != v[n-i-1]){
         return false;
      }
   }
   return true;
}
void gcd_of_whole_vector(vector<ll>&v){
   ll gcd = v[0];
   for(int i = 1; i < v.size(); i++){
      gcd = __gcd(gcd, v[i]);
   }
   cout << gcd << endl;
}
bool is_sorted(vector<ll>&v){
   for(int i = 0; i < (ll)v.size()-1; i++){
      if(v[i] > v[i+1]){
         return false;
      }
   }
   return true;
} 
void nCr(ll n, ll r){
   ll ans = 1;
   for(int i = 1; i <= r; i++){
      ans = (ans * (n-i+1))/i;
   }
   cout << ans << endl;
}
void nPr(ll n, ll r){
   ll ans = 1;
   for(int i = 1; i <= r; i++){
      ans = (ans * (n-i))/i;
   }
   cout << ans << endl;
}
void sum_of_digit(ll n){
   ll sum = 0;
   while(n){
      sum += n%10;
      n/=10;
   }
   cout << sum << endl;
}
bool isSmaller(string str1, string str2){
   int n1 = str1.length(), n2 = str2.length();

   if (n1 < n2)
      return true;
   if (n2 < n1)
      return false;

   for (int i = 0; i < n1; i++)
      if (str1[i] < str2[i])
         return true;
      else if (str1[i] > str2[i])
         return false;

   return false;
}
string findDiff(string str1, string str2){
   if (isSmaller(str1, str2)){
      swap(str1, str2);
   }
   string str = "";
   int n1 = str1.length(), n2 = str2.length();
   reverse(str1.begin(), str1.end());
   reverse(str2.begin(), str2.end());

   int carry = 0;
   for (int i = 0; i < n2; i++) {
      int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);
      if (sub < 0) {
         sub = sub + 10;
         carry = 1;
      }
      else{
         carry = 0;
      }
      str.push_back(sub + '0');
   }
   for (int i = n2; i < n1; i++) {
      int sub = ((str1[i] - '0') - carry);
      if (sub < 0) {
         sub = sub + 10;
         carry = 1;
      }
      else{
         carry = 0;
      }
      str.push_back(sub + '0');
   }
   reverse(str.begin(), str.end());

   return str;
}
int count_dig(ll n){
   int cnt = 0;
   while(n){
      n/=10;
      cnt++;
   }
   return cnt;
}
ll MEX(vector<ll>&v){
   ll n  = v.size();
   map<ll, ll>m;
   for(int i = 0; i <= n; ++i){
      m[i]++;
   }
   for(int i = 0; i < n; ++i){
      m.erase(v[i]);
   }
   return m.begin()->first;
}
// ceil of a/b = (a+b-1)/b floor is (a-1)/b

int findMinDifference(vector<string>& timePoints) {
        vector<int> v;
        for(auto &i:timePoints)
        {
            string ans;
            string hour;
            hour.push_back(i[0]);
            hour.push_back(i[1]);
            if(hour=="00")
                hour="24";
            int hrtomin=stoi(hour)*60;
            ans.push_back(i[3]);
            ans.push_back(i[4]);
           //
            //if(ans=="00")
                //ans="60";
            int num=stoi(ans)+hrtomin;
            v.push_back(num);
        }
        dbg(v);
        sort(v.begin(),v.end());
        dbg(v);
        int diff=INT_MAX;
        for(int i=1;i<v.size();++i)
        {
            diff=min(diff,v[i]-v[i-1]);
        }
        return diff;
    }
///////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n;
    cin>>n;
    vector<string> v;
    for(int i=0;i<n;++i)
    {
        string s;
        cin>>s;
        v.push_back(s);
    }
    cout<<findMinDifference(v)<<endl;
    return 0;
}



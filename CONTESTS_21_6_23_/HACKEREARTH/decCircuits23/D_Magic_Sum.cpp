/* Trilasha Mazumder */


#include <bits/stdc++.h>
using namespace std;
           
#define ll                    long long
#define ld                    long double
#define pb                    push_back
#define lb                    lower_bound
#define ub                    upper_bound
#define ff                    first
#define ss                    second
#define maxpq                 priority_queue <ll> pq;
#define minpq                 priority_queue <ll, vector<ll>, greater<ll> > pq; 
#define inpv(v)               for(auto &x: v) cin>>x;
#define fr(i,n)               for (ll i=0;i<n;++i)
#define all(str)              str.begin(), str.end()
#define pll                   pair<ll,ll>
#define printv(v)             for(auto &i: v){cout << i << " ";} cout << endl;
#define printmap(mp)          for(auto &i: mp){cout << i.first << " "<<i.second<<endl;}
#define printset(st)          for(auto &i: st){cout << i << " ";} cout << endl;
#define line                  cout<<"----------------------------------------"<<endl;
#define arrow                 cout<<"--->";
#define debugmap(mp)          for(auto &i: mp){cout << i.ff << "-->" << i.ss <<endl;} cout << endl;
#define debugset(st)          for(auto &i: st){cout << i << " ";} cout << endl;
#define fast_io               ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sp(x)                 fixed<<setprecision(x)
#define PI                    3.141592653589793238
#define bpl(n)                __builtin_popcountll(n);
#define md                    998244353
#define modval                1000000007
//#define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- */







bool isPrime(ll n){
    if(n==1) return false;
    if(n==2 || n==3) return true;
    if(n%2==0 || n%3==0) return false;
    for(ll i=5;i*i<=n;i=i+6)
    if(n%i==0 || n%(i+2)==0)
    return false;
    return true;
}
vector<ll> primes;
void solve(){
   ll n;
   cin>>n;
   vector<ll> v(n);
   inpv(v);
   vector<ll> bits(32);
   for(ll i=0;i<n;++i){
        for(ll j=0;j<31;++j){
            if(v[i]&(1<<j))
                bits[j]++;
        }
   }
   ll ans=0;
   for(ll i=0;i<n;++i){
        for(ll j=0;j<31;++j){
            if(v[i]&(1<<j)){
                ans+=(n-bits[j]);
            }else{
                ans+=bits[j];
            }
        }
        ans++;
        // cout<<ans<<endl;
   }
   ll ori=ans;
   while(!isPrime(ans)){
    ans--;
   }
   cout<<ori%ans<<endl;
}


int main(){

fast_io;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

// primes=sieve(1e7);
ll q=1;
// cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}


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



ll nCr(ll n, ll r) {
     long double sum=1;
     for(ll i = 1; i <= r; i++){
          sum = sum * (n - r + i) / i;
     }
     return sum;
}

void solve(){
  ll n,k;
  cin>>n>>k;
  vector<ll> v(n);
  inpv(v);
  sort(all(v));
  set<ll> st;
  ll cnt=0;
  map<ll,ll> mp;

  ll mx=nCr(n,3);
  ll curr=0;
  //cout<<mx<<endl;
  for(ll i=0;i<n;++i){
    ll len=n-i-1;
    if(len<2)break;
    len--;
    curr+=len*(len+1)/2;
    //cout<<curr<<endl;
    mp[curr]=i;
    //st.insert(curr);
    if(curr>=mx)break;
  }

  //line
  fr(i,k){
    ll x;
    cin>>x;
    auto it=mp.lower_bound(x);
    cout<<v[it->second]<<endl;
  }

}


int main(){

fast_io;

ll q=1;
cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}






/*----------------------------------------------------------------------------------------------------------- */
//clear adj and visited vector declared globally after each test case 
//if input newly taken then use 'resize' or else 'assign' (for dp and graphs)
//    BINARY SEARCH ~ 2-PNTS ~ DP 
//    reference for sequence(NT) --> oeis.org
//    log2(x)
//    set.lower_bound(x)
//    for mod division --> a/b use a*inverse(b) (don't divide simply)
//    set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
//    gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
/*----------------------------------------------------------------------------------------------------------- */



   
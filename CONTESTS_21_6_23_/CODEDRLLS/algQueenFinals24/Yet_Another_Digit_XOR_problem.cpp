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




ll convertbase(ll n,ll b){
     ll ans=0;
     ll p=1;
     while(n>0){
          ans+=(n%b)*p;
          p*=10;
          n/=b;
     }
     return ans;
}

ll digitalRoot(ll n,ll b){
    if(n<10) return n;
    ll sum=0;
    while(n>0){
        sum^=n%10;
        n/=10;
    }
    return sum;
}
ll calc(ll l,ll r,ll b){
     ll sum=0;
     for(int i=l;i<=r;i++){
          ll x=digitalRoot(convertbase(i,b),b);
          // cout<<x<<" ";
          sum=(sum+x)%md;
     }
     return sum;
}

void solve(){
     ll l,r,b;
     cin>>l>>r>>b;
     // cout<<calc(r,b)<<" "<<calc(l-1,b)<<endl;
     // ll ans=calc(r,b)-calc(l-1,b);
     cout<<calc(l,r,b)<<endl;
     // cout<<convertbase(12345,5)<<endl;
}

int main(){

fast_io;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

ll q=1;
cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}

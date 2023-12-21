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






vector<ll> divisors(ll n){
    vector<ll> v;
    for (ll i = 1; i*i <=n; i++){
    if(n%i==0){
        v.pb(i);
    if(i!=n/i)
        v.pb(n/i);
    }
    }
    return v;
}
void solve(){
   ll n;
   cin>>n;
   vector<ll> v(n);
   inpv(v);
   vector<ll> div=divisors(n);

   ll ans=0;
   for(ll i=0;i<div.size();++i){
    ll take=div[i];
    vector<ll> temp;
    ll cnt=0;
    ll curr=0;
    for(ll j=0;j<n;++j){
        curr+=v[j];
        cnt++;
        if(cnt==take){
            temp.pb(curr);
            cnt=0;
            curr=0;
        }
    }
    ll mx=*max_element(all(temp));
    ll mn=*min_element(all(temp));
    ans=max(ans,abs(mx-mn));
   }
   cout<<ans<<endl;
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


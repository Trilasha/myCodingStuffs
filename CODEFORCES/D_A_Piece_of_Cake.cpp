/* ...  risen_ash  ... */

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
#define sp(x)                 fixed<<setprecision(x)
#define md                    998244353
#define modval                1000000007
#define PI                    3.141592653589793238
#define bpl(n)                __builtin_popcountll(n);
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
// define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- 
                !!! DON'T GIVE-UP SEEING LENGTHY QUESTION OR ELSE KEEP REGRETTING LATER !!!                 
  --------------------------------------------------------------------------------------------------------- */







void solve(){
    ll n,m;
    cin>>n>>m;
    vector<pll> vp;
    ll q;cin>>q;
    fr(i,q){
        ll x,y;
        cin>>x>>y;
        vp.pb({x,y});
    }
    sort(all(vp));
    ll an;
    cin>>an;
    vector<ll> a,b;
    fr(i,an){
        ll x;
        cin>>x;
        a.pb(x);
    }
    //a.pb(n);

    ll bn;
    cin>>bn;
    fr(i,bn){
        ll x;
        cin>>x;
        b.pb(x);
    }
    //b.pb(m);

    map<pll,ll> mp;
    for(ll i=0;i<q;++i){
        ll x=lower_bound(all(a),vp[i].ff)-a.begin();
        ll y=lower_bound(all(b),vp[i].ss)-b.begin();
        mp[{x,y}]++;
    }

    ll mn=INT_MAX,mx=INT_MIN;

    if(mp.size()!=(an+1)*(bn+1)){
       mn=0;
    }

    for(auto &i:mp){
        mx=max(mx,i.ss);
        mn=min(mn,i.ss);
    }

    cout<<mn<<" "<<mx<<endl;
    
}


int main(){

fast_io;

ll q=1;
//cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}











/*--------------------------------------------------------------------------------------------------------- 
   reference for sequence(NT) --> oeis.org
   log2(x)
   set.lower_bound(x)
   for mod division --> a/b use a*inverse(b) (don't divide simply)
   set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
   gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
   --------------------------------------------------------------------------------------------------------- */
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






bool check(vector<ll> &v,ll grp,ll per_grp){
    ll ind=0;
    ll n=v.size();
    ll val=0;
    for(ll i=0;i<n;++i){
        ll x=min(grp,v[i]);
        if(x+val<grp){
            val+=x;
        }else{
            x+=val;
            x-=grp;
            val=x;
            ind++;
        }
        if(ind==per_grp)return 1;
    }

    return ind>=per_grp;
}
void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    inpv(v);
    ll lo=0;
    ll hi=1e18;
    ll ans=0;
    while(lo<=hi){
        ll mid=lo+(hi-lo)/2;
        if(check(v,mid,k)){
            ans=mid;
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }
    cout<<ans<<endl;
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











/*--------------------------------------------------------------------------------------------------------- 
   reference for sequence(NT) --> oeis.org
   log2(x)
   set.lower_bound(x)
   for mod division --> a/b use a*inverse(b) (don't divide simply)
   set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
   gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
   --------------------------------------------------------------------------------------------------------- */




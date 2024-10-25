// READ THE QUESTION PROPERLY FROM NEXT TIME YOU DUMBBBBB! 
// IF MISSED, ATLEAST CHECK THE ANNOUNCEMENT SECTION ONCE TO OPEN YOUR EYES!

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
#define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- */
// insead of bpow use shift operators when b=2 to avoid tle 
// do not perform more than one optimal choice/ops in a single step/loop otherwise break your head with WA
/*----------------------------------------------------------------------------------------------------------- */


ll MEX(vector<ll>&v,ll mex=1e17){
   vector<ll> temp;
   temp.pb(mex);
   for(auto &i: v){
      temp.pb(i);
   }
   ll n  = temp.size();
   map<ll, ll>m;
   for(int i = 0; i <= n; ++i){m[i]++;}
   for(int i = 0; i < n; ++i){m.erase(temp[i]);}
   return m.begin()->first;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> v;
    fr(i,n){
        ll sz;
        cin>>sz;
        vector<ll> temp;
        fr(j,sz){
            ll x;
            cin>>x;
            temp.pb(x);
        }
        v.pb(temp);
    }
    ll mx=0;
    fr(i,n){
        ll mex=MEX(v[i]);
        mx=max(mx,MEX(v[i],mex));
    }
    // cout<<mx<<endl;
    if(mx>=m){
        ll ans=(m+1)*mx;
        cout<<ans<<endl;
        return;
    }
    ll ans=(mx+1)*mx;
    ll start=mx+1;
    ans+=(m*(m+1)/2)-(start*(start-1)/2);
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
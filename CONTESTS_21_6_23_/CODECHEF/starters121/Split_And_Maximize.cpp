/*
    When talent doesn't work hard then hardwork beats talent...
    ...hardwork always pays off
*/


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
// insead of bpow use shift operators when b=2 to avoid tle 
// do not perform more than one optimal choice/ops in a single step/loop otherwise break your head with WA





void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    inpv(v);
    ll xr=0;
    for(auto &i:v){
        xr^=i;
    }
    ll ans=xr;
    for(ll i=0;i<n;++i){
        ll curr=xr^v[i];
        ll x=v[i];
        vector<ll> vis(61);
        for(ll j=60;j>=0;--j){
            if(curr&(1LL<<j))continue;
            if(x<(1LL<<j))continue;
            // ll div=x/(1LL<<j);
            // if((div%2)==0)div--;
            vis[j]=1;
            curr^=(1LL<<j);
            x-=(1LL<<j);
        }
        for(ll j=60;j>=0;--j){
            ll val=(1LL<<j);
            if(x<val)continue;
            ll div=x/val;
            if(curr&val){
                if(div%2)div--;
            }
            // if(div%2)div--;
            x-=div*val;
        }
        if(x%2){
            curr^=1;
        }
        ans=max(ans,curr);
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


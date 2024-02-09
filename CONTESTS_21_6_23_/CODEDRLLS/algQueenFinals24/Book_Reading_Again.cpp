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


class BIT{
    vector<ll> bit;
public:
    BIT(ll n)
    {
        bit.resize(n+1,0);
    }
    void update(ll x, ll val,ll n)
    {
        for(; x <= n; x += x&-x)
            bit[x] += val;
    }
    ll query(ll x)
    {
        ll sum = 0;
        for(; x > 0; x -= x&-x)
            sum += bit[x];
        return sum;
    }
};
//BIT bt(n);
//for(ll i=1;i<=n;++i){
//bt.update(i,temp[i],n);
//1-based indexing so input in vector from 1 to <=n


void solve(){
     ll q;
     cin>>q;
     ll mx=0,cur=0;
     vector<ll>v;
     vector<pll> vp;
     while(q--){
          ll t;
          cin>>t;
          ll last=cur;
          if(t==1){
               ll x;
               cin>>x;
               v.pb(x);
               cur+=x;
          }else{
               if(v.size()==0) continue;
               cur-=v.back();
               v.pop_back();
          }
         if(last<cur) vp.pb({last,cur});
     }
     
    sort(all(vp));
    ll ans=0,r=0,lastgot=0;
    for(ll i=0;i<vp.size();++i){
     if(r>max(vp[i].ff,lastgot)){
          ans+=r-max(vp[i].ff,lastgot);
          lastgot=r;
     }
     r=max(r,vp[i].ss);
    }
    cout<<ans<<endl;
}


int main(){

fast_io;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

ll qq=1;
cin>>qq;
for(ll i=0;i<qq;i++){
    solve();
}
    return 0;
}
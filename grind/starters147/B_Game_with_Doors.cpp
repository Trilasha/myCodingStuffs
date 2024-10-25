/** Let it hurt then let it go.. */

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





void solve(){
    vector<pll> vp;
    fr(i,2){
        ll x,y;
        cin>>x>>y;
        vp.pb({x,y});
    }
    sort(all(vp));
    pair<ll,ll> p1=vp[0];
    pair<ll,ll> p2=vp[1];
    if(p2.ff>p1.ss){
        cout<<1<<endl;
        return;
    }
    if(p2.ff==p1.ss){
        cout<<2<<endl;
        return;
    }
    
    if(p2.ss<=p1.ss){
        ll ans=p2.ss-p2.ff;
        if(p2.ff>p1.ff)ans++;
        if(p2.ss<p1.ss)ans++;
        cout<<ans<<endl;
        return;
    }
    ll overlap=p1.ss-p2.ff;
    ll ans=overlap;
    if(p2.ff>p1.ff)ans++;
    if(p2.ss>p1.ss)ans++;
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


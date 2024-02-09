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






void solve(){
    ll n;
    cin>>n;
    vector<ll> l(n),r(n),cost(n);
    inpv(l);inpv(r);inpv(cost);
    vector<pll> vp;
    multiset<ll> st(all(l));
    // sort(all(l));
    sort(all(r));
    for(ll i=0;i<n;++i){
        auto it=st.lower_bound(r[i]);
        it--;
        vp.pb({*it,r[i]});
        st.erase(it);
    }
    vector<pair<ll,pll>> vpp;
    for(ll i=0;i<n;++i){
        vpp.pb({vp[i].ss-vp[i].ff,vp[i]});
    }
    sort(all(vpp),greater<pair<ll,pll>>());
    sort(all(cost),greater<ll>());
    ll ans=0;
    for(ll i=0;i<n;++i){
        ans+=cost.back()*vpp[i].ff;
        cost.pop_back();
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


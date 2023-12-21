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
    vector<pll> vp;
    fr(i,n){
        ll x,y;
        cin>>x>>y;
        vp.pb({x,y});
    }
    sort(all(vp));
    map<ll,ll> mp;
    for(ll i=0;i<n;++i){
        ll tot=vp[i].ss+mp[vp[i].ff];
        ll p=tot/2;
        mp[vp[i].ff]=0;
        if(tot%2){
            // if(mp[vp[i].ff]==0)
            mp[vp[i].ff]=1;
        }
        ll ori=mp[2*vp[i].ff];
        ll a=vp[i].ff*2;
        while(p>0){
            mp[a]=0;
            if(p%2){
                // if(mp[a]==0)
                mp[a]=1;
            }
            p/=2;
            a*=2;
        }
        if(ori)
        mp[2*vp[i].ff]=ori;
        printmap(mp);
        line
    }
    ll ans=0;
    for(auto &i:mp){
        // cout<<i.ff<<" "<<i.ss<<endl;
        if(i.ss)ans++;
    }
    cout<<ans<<endl;
}


int main(){

fast_io;

ll q=1;
// cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}


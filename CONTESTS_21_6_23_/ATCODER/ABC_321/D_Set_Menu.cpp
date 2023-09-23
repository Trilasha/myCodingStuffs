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
    ll n,m,P;
    cin>>n>>m>>P;
    vector<ll> a(n),b(m);
    inpv(a);inpv(b);
    sort(all(a));
    sort(all(b));
    vector<ll> pref(m+2);
    pref[1]=b[0];
    for(ll i=2;i<=m;++i){
        pref[i]=pref[i-1]+b[i-1];
    }
    ll ans=0;
    for(ll i=0;i<n;++i){
        ll curr=a[i];
        ll req=P-curr;
        ll ind=lower_bound(all(b),req)-b.begin();
        if(ind==m){
            ans+=(pref[m]+(m*curr));
        }else{
            ll add=((ind)*curr + pref[ind]) + (m-ind)*P;
            ans+=add;
        }
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


/** lessssssgoooooo once again */

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



// if g=4 -> 0 (1,2,3)  4 (5,6,7)  8 (9,10,11)  12  (13,14,15) 16
void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    inpv(v);
    ll g=0;
    for(auto &i:v)g=__gcd(g,i);
    if(n==1){
        cout<<((v[0]>=k)?(k-1):k)<<endl;
        return;
    }
    if(g==1){
        //012345  k=10
        cout<<n+(k-1)<<endl;
        return;
    }
    ll ins=(g-1)*(n-1);
    if(k<=ins){
        ll dv=k/(g-1);
        ll rem=k%(g-1);
        ll ans=(g*dv)+rem;
        if(rem==0)ans--;
        cout<<ans<<endl;
        return;
    }
    ll ans=g*(n-1) + (k-ins);
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
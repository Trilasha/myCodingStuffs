/** zoobie doobie zoobie doobie pampaaa raa 
 *  zoobie doobie parampaaaaa
 *  zoobie doobie zoobie doobie nacheeeeee
 *  kyuuuu pagal stupid mind
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
#define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- */
// insead of bpow use shift operators when b=2 to avoid tle 
// do not perform more than one optimal choice/ops in a single step/loop otherwise break your head with WA
/*----------------------------------------------------------------------------------------------------------- */




void solve(){
    ll n,q;
    cin>>n>>q;
    vector<ll> v(n);
    inpv(v);
    vector<ll> cnt(n+1);
    for(auto &i:v)cnt[i]++;
    for(ll i=1;i<=n;++i){
        cnt[i]+=cnt[i-1];
    }
    fr(i,q){
        ll x;
        cin>>x;
        ll ans=-1;
        ll lo=0,hi=x-1;
        ll tillMid=(n)/2+1;
        while(lo<=hi){
            ll mid=(lo+hi)/2;
            ll curr=0;
            for(ll i=0;i<=n;i+=x){
                curr+=cnt[min(n,i+mid)];
                if(i>0)curr-=cnt[i-1];
            }
            if(curr>=tillMid){
                ans=mid;
                hi=mid-1;
            }else lo=mid+1;
        }
        cout<<ans<<" ";
    }
    cout<<endl;
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
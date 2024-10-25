/*
    Trilasha Mazumder
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
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>> adj(n+1);
    fr(i,n-1){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    function<pll(ll,ll,ll)> dfs=[&](ll node,ll par,ll sz){
        ll tot=1;
        ll cuts=0;
        for(auto &i:adj[node]){
            if(i!=par){
                pll p=dfs(i,node,sz);
                tot+=p.ff;
                cuts+=p.ss;
            }
        }
        if(tot>=sz){
            cuts++;
            tot=0;
        }
        // cout<<node<<"->"<<tot<<" "<<cuts<<endl;
        pll ret=make_pair(tot,cuts);
        return ret;
    };
    function<bool(ll)> check=[&](ll mid){
        pll p1=dfs(1,0,mid);
        return ((p1.ss-1)>=k);
    };

    ll lo=0,hi=n;
    ll ans=lo;
    while(lo<=hi){
        ll mid=(lo+hi)/2;
        if(check(mid)){
            ans=mid;
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }
    // cout<<check(3)<<endl;
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


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


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;
typedef tree<long long, null_type, greater_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; 




void solve(){
   int n;
   cin>>n;
   vector<pair<ll,ll>>vp;
    for(int i=0;i<n;i++){
     ll x,y;
     cin>>x>>y;
     vp.pb({x,y});
    }
    sort(all(vp));
    vector<ll>ps(n),se(n);
    pbds A;
    for(int i=0;i<n;i++){
        int x=A.order_of_key(vp[i].ss);
        ps[i]=x;
        A.insert(vp[i].ss);
    }
    pbds B;
    for(int i=n-1;i>=0;i--){
        int x=B.order_of_key(vp[i].ss);
        se[i]=x;
        B.insert(vp[i].ss);
    }
    // for(int i=0;i<n;i++){
    //     cout<<vp[i].ff<<" "<<vp[i].ss<<endl;
    // }
    // cout<<"-------------------"<<endl;
    ll ans=0;
    for(int i=0;i<n;i++){
        // cout<<ps[i]<<" "<<ss[i]<<endl;
        ans+=ps[i]*se[i];
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




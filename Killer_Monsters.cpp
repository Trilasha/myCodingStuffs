/* Trilasha Mazumder */
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
 
using namespace std;
using namespace __gnu_pbds;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
           
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
    vector<ll> v(n);
    inpv(v);
    vector<ll> ans;
    set<ll> st;
    map<ll,ll> mp;
    ll tot=0;
    for(ll i=0;i<n;++i){
       ll cnt=0;
       tot++;
       while(!st.empty()){
            ll x=*st.begin();
            if(x>v[i])break;
            cnt+=mp[x];
            mp.erase(x);
            st.erase(st.begin());
       }
       tot-=cnt;
       st.insert(v[i]);
       mp[v[i]]++;
       ans.pb(tot);
    }
    printv(ans);
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
 
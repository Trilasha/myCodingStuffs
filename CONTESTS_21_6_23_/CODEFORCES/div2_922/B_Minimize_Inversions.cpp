/*
    When talent doesn't work hard then hardwork beats talent...
    ...hardwork always pays off
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


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; 


void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n),b(n);
    inpv(a);inpv(b);
    map<ll,ll> mp1,mp2;
    pbds A,B;

    for(ll i=0;i<n;i++){
        mp1[a[i]]=b[i];
        mp2[b[i]]=a[i];
    }
    vector<ll> temp1,temp2;
    ll ans1=0;
    for(ll i=1;i<=n;++i){
        temp1.pb(i);
        temp2.pb(mp1[i]);
    }
    for(ll i=n-1;i>=0;--i){
        A.insert(temp2[i]);
        ans1+=A.order_of_key(temp2[i]);
    }
    vector<ll> temp3,temp4;
    ll ans2=0;
    for(ll i=1;i<=n;++i){
        temp3.pb(i);
        temp4.pb(mp2[i]);
    }
    for(ll i=n-1;i>=0;--i){
        B.insert(temp4[i]);
        ans2+=B.order_of_key(temp4[i]);
    }
    if(ans1<=ans2){
        printv(temp1);
        printv(temp2);
    }else{
        printv(temp4);
        printv(temp3);
    }
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


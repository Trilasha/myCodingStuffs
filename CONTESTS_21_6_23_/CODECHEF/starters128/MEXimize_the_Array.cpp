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
    ll n;
    cin>>n;
    vector<ll> v(n);
    inpv(v);
    // multiset<ll> st;
    // fr(i,n){
    //     st.insert(v[i]);
    // }
    ll ans=0;
    // for(ll  i=0;i<n;++i){
    //     if(st.find(i)!=st.end()){
    //         st.erase(st.find(i));
    //     }
    //     else{
    //         auto it=st.lower_bound(i);
    //         if(it==st.begin()){
    //             ans+=*it-i;
    //             st.erase(it);
    //         }else{
    //             auto it2=it;
    //             it2--;
    //             if(it==st.end()){
    //                 ans+=i-*it2;
    //                 st.erase(it2);
    //             }else{
    //                 ll mn=min(*it-i,i-*it2);
    //                 ans+=mn;
    //                 if(mn==*it-i){
    //                     st.erase(it);
    //                 }else{
    //                     st.erase(it2);
    //                 }
    //             }

    //         }
    //     }
    // }
    sort(all(v));
    for(ll i=0;i<n;++i){
        ans+=abs(i-v[i]);
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


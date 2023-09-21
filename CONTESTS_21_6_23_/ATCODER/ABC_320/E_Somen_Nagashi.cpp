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
    ll n,m;
    cin>>n>>m;
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    for(ll i=1;i<=n;++i){
        pq.push({0,i});
    }
    // pq.push({0,1});
    map<ll,ll> mp;
    set<ll> st;
    for(ll i=1;i<=n;++i){
        st.insert(i);
    }
    for(ll i=0;i<m;++i){
        ll t,w,s;
        cin>>t>>w>>s;
        while(!pq.empty() && pq.top().ff<=t){
            st.insert(pq.top().ss);
            pq.pop();
        }
        if(!st.empty()){
            ll ind=*st.begin();
            st.erase(st.begin());
            mp[ind]+=w;
            pq.push({t+s,ind});
        }
    }
    for(ll i=1;i<=n;++i){
        cout<<mp[i]<<endl;
    }
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


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
   ll n,m,q;
   cin>>n>>m>>q;
   vector<pll> a(n),b(m);
   set<pll> st;
   for(ll i=0;i<n;++i){
    cin>>a[i].first;
    a[i].second=i+1;
   }
    for(ll i=0;i<m;++i){
    cin>>b[i].first;
    b[i].second=i+1;
   }
   
   while(q--){
    ll x,y;
    cin>>x>>y;
    st.insert({x,y});
   }
   sort(all(a));
   sort(all(b));
//    fr(i,n){
//     cout<<a[i].ff<<" "<<a[i].ss<<endl;
//    }
   ll mx=(a[n-1].first+b[m-1].first);

   ll ans=0;
   ll i=0,j=m-1;
   ll diff=1e12;
    while(i<n && j>=0){
        ll curr=a[i].first+b[j].first;
        if(abs(curr-mx)<diff && !st.count({a[i].second,b[j].second})){
            ans=max(ans,curr);
            diff=abs(curr-mx);
        }
        if(curr<=mx)i++;
        else j--;
    }
    i=n-1,j=0;
    diff=1e12;
    while(i>=0 && j<m){
        ll curr=a[i].first+b[j].first;
        if(abs(curr-mx)<diff && !st.count({a[i].second,b[j].second})){
            ans=max(ans,curr);
            diff=abs(curr-mx);
        }
        if(curr<=mx)j++;
        else i--;
    }
    cout<<ans<<endl;

}


int main(){

fast_io;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

ll q=1;
// cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}


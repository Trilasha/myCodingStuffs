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
   ll l,m,n;
   cin>>l>>m>>n;
   vector<ll> a(l),b(m),c(n);
   inpv(a);inpv(b);inpv(c);
   set<ll> sta(all(a)),stb(all(b)),stc(all(c));;
   ll ans=1e18;
   ll x1=1e18,x2=1e18,y1=1e18,y2=1e18;
   for(ll i=0;i<l;++i){
        auto it=stb.lower_bound(a[i]);
        auto it2=stc.lower_bound(a[i]);
        if(it!=stb.end()){
            x1=*it;
        }
        if(it!=stb.begin()){
            it--;
            x2=*it;
        }
        if(it2!=stc.end()){
            y1=*it2;
        }
        if(it2!=stc.begin()){
            it2--;
            y2=*it2;
        }
        ans=min(ans,abs(a[i]-x1)+abs(x1-y1)+abs(y1-a[i]));
        ans=min(ans,abs(a[i]-x1)+abs(x1-y2)+abs(y2-a[i]));
        ans=min(ans,abs(a[i]-x2)+abs(x2-y1)+abs(y1-a[i]));
        ans=min(ans,abs(a[i]-x2)+abs(x2-y2)+abs(y2-a[i]));
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


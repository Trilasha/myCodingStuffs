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
   ll n;
   cin>>n;
   string a,b;
   cin>>a>>b;
   map<char,vector<ll>> mpa,mpb;
   fr(i,n){
        mpa[a[i]].pb(i+1);
        mpb[b[i]].pb(i+1);
   }
   vector<pll> vp;
   for(char ch='a';ch<='z';++ch){
        while(!mpa[ch].empty() && !mpb[ch].empty()){
            vp.pb({mpa[ch].back(),mpb[ch].back()});
            mpa[ch].pop_back();
            mpb[ch].pop_back();
        }
        while(!mpa[ch].empty() && !mpb['?'].empty()){
            vp.pb({mpa[ch].back(),mpb['?'].back()});
            mpa[ch].pop_back();
            mpb['?'].pop_back();
        }
        while(!mpb[ch].empty() && !mpa['?'].empty()){
            vp.pb({mpa['?'].back(),mpb[ch].back()});
            mpa['?'].pop_back();
            mpb[ch].pop_back();
        }
   }
    while(!mpa['?'].empty() && !mpb['?'].empty()){
        vp.pb({mpa['?'].back(),mpb['?'].back()});
        mpa['?'].pop_back();
        mpb['?'].pop_back();
    }
    cout<<vp.size()<<endl;
    for(ll i=0;i<vp.size();++i){
        cout<<vp[i].ff<<" "<<vp[i].ss<<endl;
    }
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


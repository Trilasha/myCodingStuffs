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
    vector<string> g(n),w(n);
    fr(i,n){
        cin>>g[i]>>w[i];
    }
    vector<vector<ll>> common(n+1,vector<ll>(n+1));
    fr(i,n){
        fr(j,n){
            if(g[i]==g[j] || w[i]==w[j]){
                common[i][j]=1;
            }
        }
    }
    vector<vector<ll>> dp((1LL<<n)+1,vector<ll>(n+1));    
    fr(i,n){
        dp[1LL<<i][i]=1;
    }
    ll ans=0;
    for(ll mask=1;mask<(1LL<<n);mask++){
        fr(i,n){
           if(dp[mask][i]){
               ll bits=bpl(mask);
               ans=max(ans,bits);
               fr(j,n){
                   if(!(mask & (1LL<<j)) && common[i][j]){
                       dp[mask|(1LL<<j)][j]=1;
                   }
               }
           }
        }
    }
    cout<<n-ans<<endl;
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


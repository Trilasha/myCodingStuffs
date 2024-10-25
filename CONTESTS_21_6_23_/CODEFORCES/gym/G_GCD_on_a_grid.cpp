/*
                    --- QUOTE OF THE DAY ---
    "When you are in darkness, listen to the whispers of your heart
    but when you are in light, listen to the thunder of your brain."
    
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
/*----------------------------------------------------------------------------------------------------------- */





void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> v(n,vector<ll>(m));
    for(ll i=0;i<n;++i){
        for(ll j=0;j<m;++j){
            cin>>v[i][j];
        }
    }
    ll g=__gcd(v[0][0],v[n-1][m-1]);
    vector<ll> div;
    for(ll i=1;i*i<=g;++i){
        if(g%i==0){
            div.pb(i);
            if(i*i!=g)div.pb(g/i);
        }
    }
    sort(all(div),greater<ll>());

    vector<vector<ll>> dp(n,vector<ll>(m,-1LL));
    function<ll(ll,ll,ll)> check=[&](ll x,ll y,ll gcd){
        ll ok=0;
        if(x==n-1 && y==m-1){
            return 1LL;
        }
        if(dp[x][y]!=-1LL) return dp[x][y];
        if(x<n-1 && v[x+1][y]%gcd==0){
            ok|=check(x+1,y,gcd);
        }
        if(y<m-1 && v[x][y+1]%gcd==0){
            ok|=check(x,y+1,gcd);
        }
        return dp[x][y]=ok;
    };

    for(auto &i:div){
        dp.assign(n,vector<ll>(m,-1LL));
        if(check(0,0,i)){
            cout<<i<<endl;
            return;
        }
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


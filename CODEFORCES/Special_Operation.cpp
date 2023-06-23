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
// define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- */






void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> v(n,vector<ll>(m)),row(n,vector<ll>(30)),col(m,vector<ll>(30));
    vector<ll> cnt(30,0);

    fr(k,n){
        fr(j,m){
            cin>>v[k][j];
            for(ll i=0;i<30;i++){
                if(v[k][j]&(1<<i)){
                    cnt[i]++;
                    row[k][i]++;
                    col[j][i]++;
                }
            }
        }
    }
    
    ll ans=INT_MIN;
    fr(i,n){
        fr(j,m){
            vector<ll> set(30),not_set(30);
            for(ll k=0;k<30;++k){
                set[k]=cnt[k]-row[i][k]-col[j][k];
                not_set[k]=(n*m-cnt[k])-(n-row[i][k])-(m-col[j][k]);
            }
            ll sum=0;
            for(ll k=0;k<30;++k){
                if(v[i][j]&(1<<k)){
                    sum+=not_set[k]*(1<<k);
                }
                else{
                    sum+=set[k]*(1<<k);
                }
            }
            ans=max(ans,sum);
        }
    }
    cout<<ans<<endl;
}


int main(){

fast_io;

ll q=1;
cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}











/*--------------------------------------------------------------------------------------------------------- 
   reference for sequence(NT) --> oeis.org
   log2(x)
   set.lower_bound(x)
   for mod division --> a/b use a*inverse(b) (don't divide simply)
   set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
   gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
   --------------------------------------------------------------------------------------------------------- */
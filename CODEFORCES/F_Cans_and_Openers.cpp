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
    vector<ll> A,B,C;
    fr(i,n){
        ll x,y;
        cin>>x>>y;
        if(x==0)A.pb(y);
        else if(x==1)B.pb(y);
        else C.pb(y);
    }
    vector<ll> X(n+1),Y(n+1);
    sort(all(A),greater<ll>());
    sort(all(B));
    sort(all(C));
    
    if(!A.empty())
    X[1]=A[0];
    for(ll i=2;i<=n;++i){
        if(i<=A.size())X[i]=X[i-1]+A[i-1];
        else X[i]=X[i-1];
    }
    ll curr=0;
    for(ll i=1;i<=n;++i){
        if(B.empty()) Y[i]=Y[i-1];
        else if(curr==0){
            if(!C.empty()){
                curr+=C.back();
                C.pop_back();
            }
            Y[i]=Y[i-1];
        }else{
            curr--;
            Y[i]=Y[i-1]+B.back();
            B.pop_back();
        }
    }
    ll ans=0;
    for(ll i=0;i<=m;++i){
        ans=max(ans,X[i]+Y[m-i]);
    }
    cout<<ans<<endl;
}


int main(){

fast_io;

ll q=1;
//cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}






/*----------------------------------------------------------------------------------------------------------- */
// clear adj and visited vector declared globally after each test case 
// if input newly taken then use 'resize' or else 'assign' (for dp and graphs)
//    BINARY SEARCH ~ 2-PNTS ~ DP 
//    reference for sequence(NT) --> oeis.org
//    log2(x)
//    set.lower_bound(x)
//    for mod division --> a/b use a*inverse(b) (don't divide simply)
//    set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
//    gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
//    if nlogn approach gives tle, go for O(n) don't sit idle (for lb/ub replace set with vector)
//    if 100% sure that chk func is correct then try changing the values of lo/hi in the main func (hit and trial)
/*----------------------------------------------------------------------------------------------------------- */



   
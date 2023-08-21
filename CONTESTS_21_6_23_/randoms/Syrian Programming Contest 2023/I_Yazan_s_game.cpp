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



// typedef struct node{
//     ll x,y;
//     ll cnt=0;
// } node;



void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> v(n,vector<ll>(m));
    ll zeroes=0;
    queue<pair<ll,ll>> q;
    ll one=0;

    fr(i,n){
        fr(j,m){
            cin>>v[i][j];
            if(v[i][j]==0)zeroes++;
            if(v[i][j]==1)one++;
        }
    }
    if(!one){
        cout<<"LOSE"<<endl;
        return;
    }

    // line
    for(ll i=0;i<n;++i){
        for(ll j=0;j<m;++j){
            if(v[i][j]==1){
                ll x=i,y=j;
                ll cnt=0;
                if(x+1<n && v[x+1][y]==0){
                    cnt++;
                }
                if(x-1>=0 && v[x-1][y]==0){
                    cnt++;
                }
                if(y+1<m && v[x][y+1]==0){
                    cnt++;
                }
                if(y-1>=0 && v[x][y-1]==0){
                    cnt++;
                }
                if(x-1>=0 && y-1>=0 && v[x-1][y-1]==0){
                    cnt++;
                }
                if(x-1>=0 && y+1<m && v[x-1][y+1]==0){
                    cnt++;
                }
                if(x+1<n && y-1>=0 && v[x+1][y-1]==0){
                    cnt++;
                }
                if(x+1<n && y+1<m && v[x+1][y+1]==0){
                    cnt++;
                }
                if(cnt==zeroes){
                    cout<<"WIN"<<endl;
                    return;
                }

        }
    }
 }


        cout<<"LOSE"<<endl;


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
/*----------------------------------------------------------------------------------------------------------- */



   
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
    vector<vector<char>> v(n,vector<char>(m));
    fr(i,n){
        fr(j,m){
            cin>>v[i][j];
        }
    }
    vector<pll> vp;
    for(ll i=0;i<=n-9;++i){
        for(ll j=0;j<=m-9;++j){
                ll okleft=0;
                ll okright=0;
                ll sleft=0;
                ll sright=0;
                for(ll a=i;a<i+3;++a){
                    for(ll b=j;b<j+3;++b){
                        if(v[a][b]=='#')okleft++;
                    }
                }
                // if(okleft!=9) break;
                for(ll a=i+6;a<i+9;++a){
                    for(ll b=j+6;b<j+9;++b){
                        if(v[a][b]=='#')okright++;
                    }
                }
                // if(okright!=9) break;
                for(ll b=j;b<j+3;++b){
                    if(v[i+3][b]=='.')sleft++;
                }
                for(ll a=i;a<i+3;++a){
                    if(v[a][j+3]=='.')sleft++;
                }
                if(v[i+3][j+3]=='.') sleft++;


                for(ll b=j+6;b<j+9;++b){
                    if(v[i+5][b]=='.')sright++;
                }
                for(ll a=i+6;a<i+9;++a){
                    if(v[a][j+5]=='.')sright++;
                }
                if(v[i+5][j+5]=='.') sright++;

                // if(i==0 && j==0)
                // cerr<<okleft<<" "<<okright<<" "<<sleft<<" "<<sright<<endl;
                if(okleft==9 && okright==9 && sleft==7 && sright==7){
                    vp.pb({i+1,j+1});
                }
        }
    }

    for(auto &i:vp){
        cout<<i.ff<<" "<<i.ss<<endl;
    }
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



   

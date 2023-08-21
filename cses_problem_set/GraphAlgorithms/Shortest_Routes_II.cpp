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


//floyd warshall algorithm --> O(n^3)
ll n,m,q;
vector<vector<ll>> matrix;

void shortest_distance(vector<vector<ll>> &matrix){
	    for(int i=1;i<=n;++i){
	        for(int j=1;j<=n;++j){
	            if(matrix[i][j]==-1)
	            matrix[i][j]=1e18;
	        }
	    }
	    
	    for(int val=1;val<=n;++val){
	       for(int i=1;i<=n;++i){
	           for(int j=1;j<=n;++j){
	               matrix[i][j]=min(matrix[i][j],matrix[i][val]+matrix[val][j]);
	           }
	       }
	    }
	    for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(matrix[i][j]==1e18)
                matrix[i][j]=-1;
            }
	    }
	}
 
void solve(){
  cin>>n>>m>>q;
  matrix.resize(n+1,vector<ll>(n+1,-1));
  fr(i,m){
    ll x,y,z;
    cin>>x>>y>>z;
    if(matrix[x][y]==-1){
        matrix[x][y]=z;
        matrix[y][x]=z;
    }
    else{
        matrix[x][y]=min(matrix[x][y],z);
        matrix[y][x]=min(matrix[y][x],z);
    }
  }
  shortest_distance(matrix);
    fr(i,q){
        ll x,y;
        cin>>x>>y;
        if(x==y)cout<<0<<endl;
        else
        cout<<matrix[x][y]<<endl;
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
/*----------------------------------------------------------------------------------------------------------- */



   

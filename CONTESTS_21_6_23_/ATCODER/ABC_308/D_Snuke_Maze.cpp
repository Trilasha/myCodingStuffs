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
//clear adj and visited vector declared globally after each test case 
//if input newly taken then use 'resize' or else 'assign' (for dp and graphs)
//    BINARY SEARCH ~ 2-PNTS ~ DP 
//    reference for sequence(NT) --> oeis.org
//    log2(x)
//    set.lower_bound(x)
//    for mod division --> a/b use a*inverse(b) (don't divide simply)
//    set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
//    gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
//    a+b=2⋅(a&b)+a⊕bs
//    a⊕b=¬(a&b)&(a∣b)
/*----------------------------------------------------------------------------------------------------------- */




ll n,m;
vector<vector<char>> v;
ll dp[505][505][6];

//snuke snuke snuke
ll ok=0;

bool recur(ll x,ll y,ll cnt){
    if(x<0 || x>=n | y<0 || y>=m)return 0;
    
    if(cnt==0 && v[x][y]!='s')return 0;
    if(cnt==1 && v[x][y]!='n')return 0;
    if(cnt==2 && v[x][y]!='u')return 0;
    if(cnt==3 && v[x][y]!='k')return 0;
    if(cnt==4 && v[x][y]!='e')return 0;
    
    if(dp[x][y][cnt]!=-1)return dp[x][y][cnt];
    dp[x][y][cnt]=0;

    if(x==n-1 && y==m-1){
        return 1;
    }
    bool ans=0;
    ans|=recur(x+1,y,(cnt+1)%5);
    ans|=recur(x-1,y,(cnt+1)%5);
    ans|=recur(x,y+1,(cnt+1)%5);
    ans|=recur(x,y-1,(cnt+1)%5);
    return dp[x][y][cnt]=ans;
}

void solve(){
    cin>>n>>m;
    v.resize(n,vector<char>(m));
    fr(i,n){
        fr(j,m){
            cin>>v[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<((recur(0,0,0))?"Yes":"No")<<endl;
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






   

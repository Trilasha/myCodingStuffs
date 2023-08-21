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


//snuke snuke snuke
ll n,m,ok=0;
vector<vector<char>> v;

struct node{
    int x,y;
    int cnt=0;
};

map<ll,char> mp={{0,'s'},{1,'n'},{2,'u'},{3,'k'},{4,'e'}};
vector<pll> dxy={{1,0},{-1,0},{0,1},{0,-1}};

void solve(){
    cin>>n>>m;
    v.resize(n,vector<char>(m));
    vector<vector<ll>> vis(n+1,vector<ll>(m+1,0));
    fr(i,n){
        fr(j,m){
            cin>>v[i][j];
        }
    }
    
    queue<node> q;
    if(v[0][0]=='s')
    q.push({0,0,1});

    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int x=it.x;
        int y=it.y;
        int cnt=it.cnt;
        if(x==n-1 && y==m-1){
                ok=1;
                break;
        }
        if(vis[x][y]) continue;
        vis[x][y]=1;
        for(auto [dx,dy]: dxy){
            int nx=x+dx;
            int ny=y+dy;
            if(nx>=0 && nx<n && ny>=0 && ny<m && v[nx][ny]==mp[cnt]){
                q.push({nx,ny,(cnt+1)%5});
            }
        }
  }


    if(ok==1)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
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






   

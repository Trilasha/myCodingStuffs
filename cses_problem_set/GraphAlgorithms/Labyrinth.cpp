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



struct node{
    int x,y;
    int cnt=0;
};

void solve(){
  int n,m;
  cin>>n>>m;
  vector<vector<char>> v(n,vector<char>(m));
  queue<node> q;
  int start_x,start_y;
  int bx,by;

  for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
        cin>>v[i][j];
        if(v[i][j]=='A'){
            start_x=i;
            start_y=j;
            q.push({i,j,0});
        }
        if(v[i][j]=='B'){
            bx=i;
            by=j;
        }
    }
  }

//   cerr<<"here"<<endl;
  int ans=INT_MAX;
  string ans_s="";
  vector<vector<int>> dp(n,vector<int>(m,INT_MAX)),vis(n,vector<int>(m,0));

  while(!q.empty()){
    auto it=q.front();
    q.pop();
    int x=it.x;
    int y=it.y;
    int cnt=it.cnt;

    dp[x][y]=min(dp[x][y],cnt);
    if(v[x][y]=='B'){
            ans=cnt;
            break;
    }

    if(vis[x][y]) continue;
    vis[x][y]=1;

    if(x+1<n && v[x+1][y]!='#'){
        q.push({x+1,y,cnt+1});
    }
    if(x-1>=0 && v[x-1][y]!='#'){
        q.push({x-1,y,cnt+1});
    }
    if(y+1<m && v[x][y+1]!='#'){
        q.push({x,y+1,cnt+1});
    }
    if(y-1>=0 && v[x][y-1]!='#'){
        q.push({x,y-1,cnt+1});
    }
  }

//   for(int i=0;i<n;++i){
//     for(int j=0;j<m;++j){
//         cerr<<dp[i][j]<<" ";
//     }
//     cerr<<endl;
//   }

  if(ans==INT_MAX){
    cout<<"NO"<<endl;
  }
  else{
    cout<<"YES"<<endl;
    cout<<ans<<endl;
    string ans_s="";
    int x=bx;
    int y=by;
    ll req=dp[bx][by];
    req--;
    while(ans_s.size()<ans){
       // cerr<<ans<<endl;
        if(x-1>=0 && dp[x-1][y]==req){
            ans_s+='D';
            x--;
        }else if(x+1<n && dp[x+1][y]==req){
            ans_s+='U';
            x++;
        }else if(y-1>=0 && dp[x][y-1]==req){
            ans_s+='R';
            y--;
        }else if(y+1<m && dp[x][y+1]==req){
            ans_s+='L';
            y++;
        }
        req--;
    }

    reverse(all(ans_s));
    cout<<ans_s<<endl;
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






   

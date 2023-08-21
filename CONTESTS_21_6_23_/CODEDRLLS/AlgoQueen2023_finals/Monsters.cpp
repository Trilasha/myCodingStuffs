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

struct node{
    ll x,y;
    ll cnt=0;
};

void solve(){
    cin>>n>>m;
    v.resize(n,vector<char>(m));
    fr(i,n){
        fr(j,m){
            cin>>v[i][j];
        }
    }
    vector<vector<ll>> dp(n,vector<ll>(m,INT_MAX)),vis(n,vector<ll>(m,0));
    queue<node> q;
    fr(i,n){
        fr(j,m){
            if(v[i][j]=='M'){
                q.push({i,j,0});
            }
        }
    }

    while(!q.empty()){
        auto it=q.front();
        q.pop();
        ll x=it.x;
        ll y=it.y;
        ll cnt=it.cnt;
    
        dp[x][y]=min(dp[x][y],cnt);
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

//   for(ll i=0;i<n;++i){
//     for(ll j=0;j<m;++j){
//         cout<<dp[i][j]<<" ";
//     }
//     cout<<endl;
//   }

   queue<node> q2;
   //ll ax=0;ll ay=0;
    fr(i,n){
        fr(j,m){
            if(v[i][j]=='A'){
                q2.push({i,j,0});
            }
        }
    }

    vector<vector<ll>> dp2(n,vector<ll>(m,INT_MAX)),vis2(n,vector<ll>(m,0));
    ll ans=-1;
    ll xx=-1,yy=-1;

    while(!q2.empty()){
        auto it=q2.front();
        q2.pop();
        ll x=it.x;
        ll y=it.y;
        ll cnt=it.cnt;
    
        dp2[x][y]=min(dp2[x][y],cnt);

        if(x==0 || y==0 || x==n-1 || y==m-1){
            ans=cnt;
            xx=x;
            yy=y;
            break;
        }
        if(vis2[x][y]) continue;
        vis2[x][y]=1;
    
        if(x+1<n && v[x+1][y]!='#' && (dp[x+1][y]>(cnt+1) || dp[x+1][y]==INT_MAX)){
            q2.push({x+1,y,cnt+1});
        }
        if(x-1>=0 && v[x-1][y]!='#' && (dp[x-1][y]>(cnt+1) || dp[x-1][y]==INT_MAX)){
            q2.push({x-1,y,cnt+1});
        }
        if(y+1<m && v[x][y+1]!='#' && (dp[x][y+1]>(cnt+1) || dp[x][y+1]==INT_MAX)){
            q2.push({x,y+1,cnt+1});
        }
        if(y-1>=0 && v[x][y-1]!='#' && (dp[x][y-1]>(cnt+1) || dp[x][y-1]==INT_MAX)){
            q2.push({x,y-1,cnt+1});
        }
  }


  if(ans==-1){
      cout<<"NO"<<endl;
  }
  else{
       cout<<"YES"<<endl;
       cout<<ans<<endl;
       string ans_s="";
        ll x=xx;
        ll y=yy;
        ll req=dp2[xx][yy];
        req--;
        while(ans_s.size()<ans){
        // cerr<<ans<<endl;
            if(x-1>=0 && dp2[x-1][y]==req){
                ans_s+='D';
                x--;
            }else if(x+1<n && dp2[x+1][y]==req){
                ans_s+='U';
                x++;
            }else if(y-1>=0 && dp2[x][y-1]==req){
                ans_s+='R';
                y--;
            }else if(y+1<m && dp2[x][y+1]==req){
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






   

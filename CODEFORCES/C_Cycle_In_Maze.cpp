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
#define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- */




//DLRU
vector<pair<int,int>> dxy={{1,0},{0,-1},{0,1},{-1,0}};

struct node{
    int x,y;
    int cnt=0;
    string s;
};

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<char>> v(n,vector<char>(m));
    vector<vector<int>> vis(n,vector<int>(m,0)),dp(n,vector<int>(m,INT_MAX));
    if(k%2){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    int startx=-1,stary=-1;
    queue<node> q;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>v[i][j];
            if(v[i][j]=='X'){
                startx=i;
                stary=j;
                q.push({i,j,0,""});
            }
        }
    }
    int ok=0;string ans="";
    while(!q.empty()){
        int x=q.front().x;
        int y=q.front().y;
        int cnt=q.front().cnt;
        string s=q.front().s;
        q.pop();
        //dp[x][y]=min(dp[x][y],cnt);
        if(v[x][y]=='X' && cnt!=0){
            ok=1;
            if(s<ans || ans==""){
                ans=s;
            }
        }
        if(vis[x][y]){
            continue;
        }
        vis[x][y]=1;
        for(auto &i: dxy){
            int newx=x+i.ff;
            int newy=y+i.ss;
            char ch=((i.ff==1)?'D':((i.ff==-1)?'U':((i.ss==1)?'R':'L')));
            if(newx>=0 && newx<n && newy>=0 && newy<m && v[newx][newy]!='*'){
                q.push({newx,newy,cnt+1,s+ch});
            }
        }
    }
    if(!ok){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    int rem=k-ans.size();
    while(rem){
        cout<<ans[0]<<ans[1];
        rem-=2;
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



   

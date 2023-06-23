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






// 11 12 13
// 21 22 23
// 31 32 33

void solve(){
    ll n,m;
    cin>>n>>m;
    ll k;
    cin>>k;
    queue<pair<ll,ll>> q;
    vector<vector<ll>> vis(n+1,vector<ll>(m+1,0));
    fr(i,k){
        ll x,y;
        cin>>x>>y;
        q.push({x,y});
        vis[x][y]=1;
    }

    pll p1;
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        ll ok=0;
        ll x=it.ff;
        ll y=it.ss;
        if(x-1>=1 && vis[x-1][y]==0){
            q.push({x-1,y});
            vis[x-1][y]=1;
            ok=1;
        }
        if(x+1<=n && vis[x+1][y]==0){
            q.push({x+1,y});
            vis[x+1][y]=1;
            ok=1;
        }
        if(y-1>=1 && vis[x][y-1]==0){
            q.push({x,y-1});
            vis[x][y-1]=1;
            ok=1;
        }
        if(y+1<=m && vis[x][y+1]==0){
            q.push({x,y+1});
            vis[x][y+1]=1;
            ok=1;
        }

        if(ok==0){
            p1.ff=x;
            p1.ss=y;
        }
    }
    cout<<p1.ff<<" "<<p1.ss<<endl;
}


int main(){

fast_io;

freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);

ll q=1;
//cin>>q;
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
   a+b=2⋅(a&b)+a⊕b
   a⊕b=¬(a&b)&(a∣b)
   --------------------------------------------------------------------------------------------------------- */
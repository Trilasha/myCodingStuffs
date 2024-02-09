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





vector<pll> dxy={{-1,0},{1,0},{-1,-1},{1,1}};
void solve(){
    ll n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll>> v(n,vector<ll>(m)),cnt(n,vector<ll>(m,0)),vis;
    for(ll i=0;i<n;++i){
        for(ll j=0;j<m;++j){
            cin>>v[i][j];
        }
    }

    function<void(ll,ll)> dfs=[&](ll x,ll y){
        if(vis[x][y]) return;
        vis[x][y]=1;
        cnt[x][y]++;
        for(auto &i:dxy){
            ll nx=x+i.ff,ny=y+i.ss;
            if(nx>=0 && nx<n && ny>=0 && ny<m && v[nx][ny]<=v[x][y]){
                dfs(nx,ny);
            }
        }
    };

    fr(i,q){
        ll x,y;
        cin>>x>>y;
        x--,y--;
        vis.assign(n,vector<ll>(m,0));
        dfs(x,y);
    }
    ll mx=0,x=0,y=0;
    fr(i,n){
        fr(j,m){
            if(cnt[i][j]>mx){
                mx=cnt[i][j];
                x=i+1,y=j+1;
            }
        }
    }
    cout<<x<<" "<<y<<" "<<mx<<endl;
 
}


int main(){

fast_io;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

ll q=1;
// cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}


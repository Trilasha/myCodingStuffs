/* ...  risen_ash  ... */

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
#define sp(x)                 fixed<<setprecision(x)
#define md                    998244353
#define modval                1000000007
#define PI                    3.141592653589793238
#define bpl(n)                __builtin_popcountll(n);
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
// define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- 
                !!! DON'T GIVE-UP SEEING LENGTHY QUESTION OR ELSE KEEP REGRETTING LATER !!!                 
  --------------------------------------------------------------------------------------------------------- */





//BINARY-LIFTING

ll LOG;
vector<ll> depth;
vector<vector<ll>> up;
void precal(ll n,vector<ll> &parent){
    LOG=0;
    while((1<<LOG)<=n){
        LOG++;
    }
    up.resize(n+1,vector<ll>(LOG+1));
    depth.resize(n+1);
    for(ll i=1;i<LOG;++i){
        for(ll j=0;j<n;++j){
            up[j][0]=parent[j];
            if(j!=0){
                depth[j]=depth[parent[j]]+1;
            }
            up[j][i]=up[up[j][i-1]][i-1];
        }
    }

}
void solve(){
    ll n,q;
    cin>>n>>q;
    vector<ll> parent(n+1);
    for(ll i=1;i<n;++i){
        ll x;
        cin>>x;
        x--;
        parent[i]=x;
    }
    //printv(parent);
    precal(n,parent);

    for(ll i=0;i<q;++i){
        // line
        ll node,k;
        cin>>node>>k;
        node--;
        ll ans;
        if(depth[node]<k){
            cout<<-1<<endl;
        }else{
            for(ll i=0;i<LOG;++i){
                if(k&(1<<i)){
                    node=up[node][i];
                }
            }
            cout<<node+1<<endl;
        }
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


/*
    for(int i=LOG-1;i>=0;i--){
        if(k>=(1<<i)){
            node=up[node][j];
            k-=1<<j;
        }
    }

    up[10][0]=9;
    up[10][1]=up[9][0]=8;
    up[10][2]=up[8][1]=4;
    up[10][3]=up[4][2]=?

    up[9][0]=8;
    up[9][1]=up[8][0]=7;
    up[9][2]=up[7][1]=1;

        
    void dfs(int a) {
        for(int b : children[a]) {
            depth[b] = depth[a] + 1;
            up[b][0] = a; // a is parent of b
            for(int j = 1; j < LOG; j++) {
                up[b][j] = up[up[b][j-1]][j-1];
            }
            dfs(b);
        }
    }

*/










/*--------------------------------------------------------------------------------------------------------- 
   reference for sequence(NT) --> oeis.org
   LOG2(x)
   set.lower_bound(x)
   for mod division --> a/b use a*inverse(b) (don't divide simply)
   set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
   gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
   --------------------------------------------------------------------------------------------------------- */
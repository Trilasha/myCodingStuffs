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
vector<ll> depth,parent;
vector<vector<ll>> up;

void precal(ll n,vector<ll> &parent){
    LOG=0;
    while((1<<LOG)<=n){
        LOG++;
    }
    up.resize(n+1,vector<ll>(LOG+1));
    depth.resize(n+1);
    for(ll j=0;j<n;++j){
        up[j][0]=parent[j];
    }
    for(ll i=1;i<=LOG;++i){
        for(ll j=0;j<n;++j){
            up[j][0]=parent[j];
            if(j!=0){
                depth[j]=depth[parent[j]]+1;
            }
            up[j][i]=up[up[j][i-1]][i-1];
        }
    }

}

ll get_lca(ll a,ll b){
    if(depth[a]<depth[b]){
        swap(a,b);
    }
    //cerr<<depth[a]<<" "<<depth[b]<<endl;
    ll k=depth[a]-depth[b];
    cerr<<k<<endl;
    for(ll i=LOG-1;i>=0;--i){
        cerr<<(1<<i)<<" "<<(k&(1<<i))<<endl;
        if(k&(1<<i)){
            cerr<<up[a][1]<<endl;
            a=up[a][i];
        }
    }
    //cerr<<a<<" "<<b<<endl;

    //important
    if(a == b) {
		return a+1;
	}
    
    for(ll i=LOG-1;i>=0;--i){
        if(up[a][i]!=up[b][i]){
            a=up[a][i];
            b=up[b][i];
        }
    }

    return up[a][0]+1;
}
void solve(){
    ll n,q;
    cin>>n>>q;
    parent.resize(n+1);
    for(ll i=1;i<n;++i){
        ll x;
        cin>>x;
        x--;
        parent[i]=x;
    }

    precal(n,parent);

    for(ll i=0;i<q;++i){
        ll x,y;
        cin>>x>>y;
        x--;y--;
        //cout<<depth[x]<<" "<<depth[y]<<endl;
        cout<<get_lca(x,y)<<endl;
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

    up[10][0]=9;
    up[10][1]=up[9][0]=8;
    up[10][2]=up[8][1]=4;
    up[10][3]=up[4][2]=?

    up[9][0]=8;
    up[9][1]=up[8][0]=7;
    up[9][2]=up[7][1]=1;


0 to LOG-1 in last for loop will not work. Because we are moving both nodes one by one to the level just below the lowest common ancestor.

Let us call this level as 'Limiting level'.

Suppose, we have to make 2 jumps to reach limiting level.


As you start for loop from 0, you'll check for 2^0 jumps from initial position, then it is allowed (as they will not be equal) , therefore you will make jump. From that position, you can check for 2, 4 ,8... jumps. But we are just 1 jump away from limiting level.

Therefore we can not reach limiting level here, that is why it is not working.
*/










/*--------------------------------------------------------------------------------------------------------- 
   reference for sequence(NT) --> oeis.org
   LOG2(x)
   set.lower_bound(x)
   for mod division --> a/b use a*inverse(b) (don't divide simply)
   set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
   gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
   --------------------------------------------------------------------------------------------------------- */
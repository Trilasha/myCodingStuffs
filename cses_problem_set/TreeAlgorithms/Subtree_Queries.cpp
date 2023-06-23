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
// define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- */




//Euler Tour Technique -> to flatten the tree into an array 
//Binary Indexed Tree (Fenwick Tree)  -> to perform the update and query operations on the flattened tree
//considering all 1-based indexing



vector<vector<ll>> adj(200005);
vector<ll> start(200005),endd(200005);
vector<ll> val;ll timer = 1;

class BIT{
    vector<ll> bit;
public:
    BIT(ll n){
        bit.resize(n+1,0);
    }
    void update(ll x, ll val,ll n){
        for(; x <= n; x += x&-x)
            bit[x] += val;
    }
    ll query(ll x){
        ll sum = 0;
        for(; x > 0; x -= x&-x)
            sum += bit[x];
        return sum;
    }
};

void euler(ll node,ll par=-1){
    start[node]=timer++;
    for(auto child:adj[node]){
        if(child!=par){
            euler(child,node);
        }
    }
    endd[node]=timer;
}


void solve(){
    ll n,q;
    cin>>n>>q;
    val.resize(n+1);
    for(ll i=1;i<=n;++i){
        cin>>val[i];
    }

    fr(i,n-1){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    euler(1);

    BIT bt(n);
    for(ll i=1;i<=n;++i){
        bt.update(start[i],val[i],n);
    }

    fr(i,q){
        ll type;
        cin>>type;
        if(type==1){
            ll node,new_val;
            cin>>node>>new_val;
            bt.update(start[node],-val[node]+new_val,n);
            val[node]=new_val;
        }else{
            ll node;
            cin>>node;
            cout<<bt.query(endd[node]-1)-bt.query(start[node]-1)<<endl;
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











/*--------------------------------------------------------------------------------------------------------- 
   reference for sequence(NT) --> oeis.org
   log2(x)
   set.lower_bound(x)
   for mod division --> a/b use a*inverse(b) (don't divide simply)
   set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
   gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
   --------------------------------------------------------------------------------------------------------- */
#include <bits/stdc++.h>
using namespace std;
           
#define ll                    long long
#define ld                    long double
#define pb                    push_back
#define popb                  pop_back
#define lb                    lower_bound
#define ub                    upper_bound
#define ff                    first
#define ss                    second
#define maxpq                 priority_queue <ll> pq;
#define minpq                 priority_queue <ll, vector<ll>, greater<ll> > pq; 
#define sp(x)                 fixed<<setprecision(x)
/// ---------------------------------------------------------------------------------------------------------- ///
#define md                    998244353
#define modval                1000000007
#define PI                    3.141592653589793238
#define bpl(n)                __builtin_popcountll(n);
/// ---------------------------------------------------------------------------------------------------------- ///
#define inp(n)                ll n;cin>>n;
#define inpv(v)               for(auto &x: v) cin>>x;
#define make(arr,n)           ll arr[n]; fr(i,n) cin>>arr[i];
/// ---------------------------------------------------------------------------------------------------------- ///
#define fr(i,n)               for (ll i=0;i<n;++i)
#define frs(i,k,n)            for(ll i=k;i<n;++i)
#define all(str)              str.begin(), str.end()
#define pll                   pair<ll,ll>
#define fast_io               ios_base::sync_with_stdio(false);cin.tie(NULL);


// class DSU{
//     vector<ll> par,size;
    
// public:
//     ll tot_components;
//     DSU(ll n)
//     {
//         size.resize(n+1,1);
//         par.resize(n+1);
//         for(ll i=1;i<=n;++i)
//         par[i]=i;
 
//         tot_components=n;
//     }
 
 
//     ll findPar(ll node)
//     {
//         if (node==par[node])
//         return node;
//         return par[node]=findPar(par[node]);
//     }
 
//     ll getsize(ll node){
//         return size[findPar(node)];
//     }
 
//     void unite(ll u,ll v)
//     {
//         ll ult_u=findPar(u);
//         ll ult_v=findPar(v);
//         if(ult_u==ult_v)return;
//         if(size[ult_u]<size[ult_v])
//         {
//             size[ult_v]+=size[ult_u];
//             par[ult_u]=ult_v;
//         }
//         else
//         {
//             size[ult_u]+=size[ult_v];
//             par[ult_v]=ult_u;
//         }
//         tot_components--;
//     }
// };
 
 /**
  *dfknrfojrbfwrkjbfewjfbrwhbfhrwfhbrhfbrhfbhrnbfghnrbhgbrhgbhfrbgjlrbfjlwrhfnrwkifnrjfbjrwbfjrbfjrbjfbrjbfj
  djcbdkjbdjbdjkcbdjbdjbfjdfbdjbfhdbfhedbfhdebfhdbfjdbfffffffffffffffffffffffffffffffffffffffffffffffffffffbhdfb
  jfnddjbfdhbfhdbfhedbfjdebfjdbjfdbjfdjbfjdbfdsbfhdbfdsbfdhfbjdbfjbdjfbjdbfjbdsjfbdjbfjdsbfjdbfjbdsjfbjdsbfjdbfjbsdjfds
  dfkdnfjdfjdsbfjdbfhdbfhdsbfhbdshfjdsbfjdsbfjdsbfjbdsfbdsbfjdsbfhdsbfbdsjfbjdbfjsdnfjdsnfjdbfjdbfjdbsjfbdsjfbjdbfjksdbfkdsjf

  dsfnjdsndsjfndfjlndsjl
  * 
  */



void solve(){
    ll x,k;
    cin>>x>>k;

    if(x==1){
        cout<<1<<endl;
        cout<<1<<endl;
        return;
    }

    if(x%k){
        cout<<1<<endl;
        cout<<x<<endl;
        return;
    }

    cout<<2<<endl;
    cout<<x-1<<" ";
    cout<<1<<endl;
}


int main(){

fast_io;

ll q=1;
cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
           
#define ll                    long long
#define ld                    long double
#define pb                    push_back
#define popb                  pop_back
#define lb                    lower_bound
#define ub                    upper_bound
#define ff                    first
#define ss                    second
#define maxpq                 priority_queue <ll> pq;
#define minpq                 priority_queue <ll, vector<ll>, greater<ll> > pq; 
#define sp(x)                 fixed<<setprecision(x)
/// ---------------------------------------------------------------------------------------------------------- ///
#define md                    998244353
#define modval                1000000007
#define PI                    3.141592653589793238
#define bpl(n)                __builtin_popcountll(n);
/// ---------------------------------------------------------------------------------------------------------- ///
#define inp(n)                ll n;cin>>n;
#define inpv(v)               for(auto &x: v) cin>>x;
#define make(arr,n)           ll arr[n]; fr(i,n) cin>>arr[i];
/// ---------------------------------------------------------------------------------------------------------- ///
#define fr(i,n)               for (ll i=0;i<n;++i)
#define frs(i,k,n)            for(ll i=k;i<n;++i)
#define all(str)              str.begin(), str.end()
#define pll                   pair<ll,ll>
#define fast_io               ios_base::sync_with_stdio(false);cin.tie(NULL);


// class DSU{
//     vector<ll> par,size;
    
// public:
//     ll tot_components;
//     DSU(ll n)
//     {
//         size.resize(n+1,1);
//         par.resize(n+1);
//         for(ll i=1;i<=n;++i)
//         par[i]=i;
 
//         tot_components=n;
//     }
 
 
//     ll findPar(ll node)
//     {
//         if (node==par[node])
//         return node;
//         return par[node]=findPar(par[node]);
//     }
 
//     ll getsize(ll node){
//         return size[findPar(node)];
//     }
 
//     void unite(ll u,ll v)
//     {
//         ll ult_u=findPar(u);
//         ll ult_v=findPar(v);
//         if(ult_u==ult_v)return;
//         if(size[ult_u]<size[ult_v])
//         {
//             size[ult_v]+=size[ult_u];
//             par[ult_u]=ult_v;
//         }
//         else
//         {
//             size[ult_u]+=size[ult_v];
//             par[ult_v]=ult_u;
//         }
//         tot_components--;
//     }
// };
 
 /**
  *dfknrfojrbfwrkjbfewjfbrwhbfhrwfhbrhfbrhfbhrnbfghnrbhgbrhgbhfrbgjlrbfjlwrhfnrwkifnrjfbjrwbfjrbfjrbjfbrjbfj
  djcbdkjbdjbdjkcbdjbdjbfjdfbdjbfhdbfhedbfhdebfhdbfjdbfffffffffffffffffffffffffffffffffffffffffffffffffffffbhdfb
  jfnddjbfdhbfhdbfhedbfjdebfjdbjfdbjfdjbfjdbfdsbfhdbfdsbfdhfbjdbfjbdjfbjdbfjbdsjfbdjbfjdsbfjdbfjbdsjfbjdsbfjdbfjbsdjfds
  dfkdnfjdfjdsbfjdbfhdbfhdsbfhbdshfjdsbfjdsbfjdsbfjbdsfbdsbfjdsbfhdsbfbdsjfbjdbfjsdnfjdsnfjdbfjdbfjdbsjfbdsjfbjdbfjksdbfkdsjf

  dsfnjdsndsjfndfjlndsjl
  * 
  */

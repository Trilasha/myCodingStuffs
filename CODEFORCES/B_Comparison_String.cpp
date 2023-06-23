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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll curr=0;
    ll a=0;
    ll b=0;
    ll ans=0;
    ll ok=0;

    for(ll i=0;i<n;++i){
        if(s[i]=='<' && ok==0){
            b=0;
            ans=max(ans,curr+1);
            ok=1;
            curr=1;
        }
        else if(ok==1 && s[i]=='<'){
            curr++;
        }else if(s[i]=='>' && b==0){
              ok=0;
              ans=max(ans,curr+1);
              b=1;
              curr=1;  
        }else if(b==1 && s[i]=='>'){
            curr++;
        }
    }

    ans=max(ans,curr+1);
    cout<<ans<<endl;


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

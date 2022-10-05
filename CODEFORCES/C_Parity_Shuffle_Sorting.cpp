/// ------------------------------------HEADER-FILES and ABBREVIATIONS---------------------------- ///
#include <bits/stdc++.h>
using namespace std;
#define ll                    long long
#define ld                    long double
#define pb                    push_back
#define popb                  pop_back
#define lb                    lower_bound
#define ub                    upper_bound
#define umap                  unordered_map
#define uset                  unordered_set
#define ff                    first
#define ss                    second
#define pi                    pair<ll,ll> 
#define maxpq                 priority_queue <ll> pq;
#define minpq                 priority_queue <ll, vector<ll>, greater<ll> > pq; 
/// ------------------------------------PRE-DEFINED VALUES---------------------------------------- ///
#define maxval                1000000007
#define PI                    3.141592653589793238
#define bpl(n)                __builtin_popcountll(n);
/// ------------------------------------TAKING INPUTS--------------------------------------------- ///
#define inp(n)                ll n;cin>>n;
#define inpv(v)               for(auto &x: v) cin>>x;
#define make(arr,n)           ll arr[n]; fr(i,n) cin>>arr[i];
/// ------------------------------------FOR LOOPS AND SORT---------------------------------------- ///
#define fr(i,n)               for (ll i=0;i<n;++i)
#define frs(i,k,n)            for(ll i=k;i<n;++i)
#define fA(i,a,n)             for(ll i=a;i<=(n);++i)
#define fD(i,a,n)             for(ll i=a;i>=(n);--i)
#define dsort(arr)            sort(arr,arr+n,greater<ll>())
#define asort(arr)            sort(arr,arr+n)
#define allasort(str)         sort(str.begin(), str.end())
#define alldsort(str)         sort(str.begin(), str.end(),greater<char>())
#define all(str)              str.begin(), str.end()
#define pll                   pair<ll,ll>
/// ------------------------------------PRINTOUTS------------------------------------------------- ///
#define printv(v)             for(auto &i: v){cout << i << " ";} cout << endl;
#define printmap(mp)          for(auto &i: mp){cout << i.first << " "<<i.second<<endl;}


/// ---------------------------------------------------------------------------------------------- ///
//ceil(log2(x))
    
/// ---------------------------------------------------------------------------------------------- ///
    


bool check(vector<ll> &v)
{
    frs(i,1,v.size())
    {
        if(v[i]<v[i-1])
        return false;
    }
    return true;
}
void solve(){
   inp(n);
   vector<ll> v(n);
   inpv(v);
   vector<pll> vp;
   if(check(v))
   {
    cout<<0<<endl;
    return;
   }
   ll ct=0;
   ll sum=v[0]+v[n-1];
   if(sum%2==0)
   v[0]=v[n-1];
   else
   v[n-1]=v[0];
   vp.pb({1,n});
   frs(i,1,n-1)
   {
//     if((v[i]+v[i-1])%2!=0)
//     {
//         if(v[i]<=v[i-1])
//         {
//         v[i]=v[i-1];
//         vp.pb({i,i+1});
//         }
//         else
//         {
//         v[n-1]=v[i];
//         vp.pb({i+1,n});
//         }
//    }
//    else if((v[i]+v[i-1])%2==0)
//     {
//         if(v[i]<=v[i-1])
//         {
//         v[i]=v[n-1];
//         vp.pb({i+1,n});
//         }
//         else
//         {
//         v[i-1]=v[i];
//         vp.pb({i,i+1});
//         }
if((v[i]+v[0])%2==0)
vp.pb({i+1,n});
else
vp.pb({1,i+1});
   //}
   ct++;
}
//    if(v[n-1]<v[n-2])
//    {
//     ct++;
//     v[n-1]=v[n-2];
//     vp.pb({n-1,n});
//    }
  // printv(v);
   cout<<ct+1<<endl;
   for(auto &i:vp)
   {
    cout<<i.first<<" "<<i.second<<endl;
   }
}
    
int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);

    
ll q;
cin>>q;
while(q--)
{
    solve();
}
    return 0;
}






/*
//
string s=to_string(bitset<64> b(10));

//
using namespace std;
const ll N=1e9+10;
vector<ll> g[N];
bool vis[N];
void dfs(ll vertex)
{
vis[vertex]=true;
for(ll child:g[vertex])
{
    if(vis[child])continue;
    dfs(child);
}
}
*/
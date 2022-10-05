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
    



void solve(){
   inp(n);
   vector<ll> type(n),val(n);
   inpv(type);
   inpv(val);
   vector<ll> fire;
   vector<ll> frost;
   fr(i,n)
   {
    if(type[i]==0)
    fire.pb(val[i]);
    else
    frost.pb(val[i]);
   }
   // printv(fire);
   //printv(frost);

   if(fire.size()==0 || frost.size()==0)
   {
    ll sum=0;
    fr(i,n)
    sum+=val[i];
    cout<<sum<<endl;
    return;
   }
   sort(fire.begin(),fire.end(),greater<ll>());
   sort(frost.begin(),frost.end(),greater<ll>());
//printv(fire);
//printv(frost);

   //
   ll inda=0;
   ll indb=0;
   vector<ll> temp;
   temp.pb(fire[fire.size()-1]);
   ll set=0;
   while(temp.size()!=n)
   {
    if(indb!=frost.size())
    {
    if(set==0)
    temp.pb(2*frost[indb++]);
    else
    temp.pb(frost[indb++]);
    set=1;
    }
    if(temp.size()==n)
    break;
    if(inda<(fire.size()-1))
    {
    if(set==1)
    temp.pb(2*fire[inda++]);
    else
    temp.pb(fire[inda++]);
    set=0;
    }
   }
  // printv(temp);
   ll sum1=accumulate(temp.begin(),temp.end(),0);
   //cout<<sum1<<endl;


   //
   inda=0;
   indb=0;
   vector<ll> temp2;
   temp2.pb(frost[frost.size()-1]);
   ll sety=1;
   while(temp2.size()!=n)
   {
    if(inda!=fire.size())
    {
    if(sety==1)
    temp2.pb(2*fire[inda++]);
    else
    temp2.pb(fire[inda++]);
    sety=0;
    }
    if(temp2.size()==n)
    break;
    if(indb<(frost.size()-1))
    {
    if(sety==0)
    temp2.pb(2*frost[indb++]);
    else
    temp2.pb(frost[indb++]);
    sety=1;
    }
   }

   
  //printv(temp2);
   ll sum2=accumulate(temp2.begin(),temp2.end(),0);
  // cout<<sum2<<endl;
   cout<<max(sum1,sum2)<<endl;

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
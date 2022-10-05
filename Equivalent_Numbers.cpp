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
/// ------------------------------------PRINTOUTS---------------------------------------- ///
#define printv(v)             for(auto &i: v){cout << i << " ";} cout << endl;
#define printmap(mp)          for(auto &i: mp){cout << i.first << " "<<i.second<<endl;}

    
vector<ll> printprimefactors(ll n)
{
    vector<ll> v;
    if(n<=1) return v;
    while(n%2==0)
    {
        //cout<<2;
        v.pb(2);
        n=n/2;
    }
     while(n%3==0)
    {
        //cout<<3;
        // s.insert(3);
        v.pb(3);
        n=n/3;
    }
    for (ll i = 5; i*i<=n; i=i+6)
    {
        while (n%i==0)
        {
           // cout<<i;
        //    s.insert(i);
        v.pb(i);
            n=n/i;
        }
        while(n%(i+2)==0)
        {
           // cout<<i+2;
        //    s.insert(i+2);
        v.pb(i+2);
            n=n/(i+2);
        }
    }
    if(n>3)
   // cout<<n;
//    s.insert(n);
v.pb(n);
    return v;
    //i/p-->450
    //o/p-->23355
}
void solve(){
   inp(a);
   inp(b);
   vector<ll> sa=printprimefactors(a);
   vector<ll> sb=printprimefactors(b);
   set<ll> s1;
   set<ll> s2;
   fr(i,sa.size())
   {
    s1.insert(sa[i]);
   }
    fr(i,sb.size())
   {
    s2.insert(sb[i]);
   }
   if(s1.size()==1 and s2.size()==1 && sa[0]==sb[0])
   cout<<"YES"<<endl;
   else
   cout<<"NO"<<endl;
//    if(sa.size()==1 && sb.size()==1)
//    {
//     for(auto &i:sa)
//     ll t=i;
//    }
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
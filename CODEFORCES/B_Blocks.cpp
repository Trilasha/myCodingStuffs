/*
Trilasha Mazumder
2112063
*/
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
   string s;
   cin>>s;
   vector<pll> vp;
   set<char> fool;
   fr(i,s.size())
   fool.insert(s[i]);
   if(fool.size()==1)
   {
    cout<<0<<endl;
    return;
   }
   //
   for(ll i=0;i<s.size()-1;++i)
   {
    if(s[i]=='W')
    {
        s[i]='B';
        if(s[i+1]=='B')
        s[i+1]='W';
        else
        s[i+1]='B';
        vp.pb({i+1,i+2});
    }
   }
   set<char> sss;
   fr(i,s.size())
   sss.insert(s[i]);
  if(sss.size()==1)
   {
    cout<<vp.size()<<endl;
    for(auto &i:vp)
    cout<<i.first<<" ";
    cout<<endl;
    return;
   }
   sss.clear();
   //
   for(ll i=0;i<s.size()-1;++i)
   {
    if(s[i]=='B')
    {
        s[i]='W';
        if(s[i+1]=='B')
        s[i+1]='W';
        else
        s[i+1]='B';
        vp.pb({i+1,i+2});
    }
   }
   fr(i,s.size())
   sss.insert(s[i]);
 if(sss.size()==1)
   {
    cout<<vp.size()<<endl;
    for(auto &i:vp)
    cout<<i.first<<" ";
    cout<<endl;
    return;
   }
   cout<<-1<<endl;
}
    
int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);

    
ll q;
//cin>>q;
q=1;
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
stack,queue->no index access
use deque,vectors
-->assign(n,val)available for both
-->take size +1(extra) for vectors
*/
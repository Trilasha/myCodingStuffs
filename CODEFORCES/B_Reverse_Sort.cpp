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
   vector<ll> one,zero;
   vector<vector<ll>> v(n);
   
   //
   string monkey=s;
   allasort(monkey);
   if(monkey==s)
   {
    cout<<0<<endl;
    return;
   }

   //
   ll index=0;
   ll i,j;
    i=-1;
    j=s.size();
   while(1)
   {
   while(1)
   {
    //cout<<i<<" "<<j<<endl;
     if(one.size()<=zero.size())
    i++;
     if(i==j)
    break;
    if(s[i]=='1' && one.size()<=zero.size())
    {
        one.pb(i+1);
    }
     if(i==j)
    break;
    if(zero.size()<=one.size())
    j--;
    if(s[j]=='0' && one.size()>=zero.size())
    {
        zero.pb(j+1);
    }
    
     if(i==j)
    break;
   }
   // printv(one);
    //printv(zero);
     set<ll> st;
   for(ll i=0;i<min(one.size(),zero.size());++i)
   {
    swap(s[one[i]-1],s[zero[i]-1]);
    st.insert(one[i]);
    st.insert(zero[i]);
   }
   v[index].pb(st.size());
   for(auto &i:st)
   v[index].pb(i);
   index++;
   one.clear();
   zero.clear();
   st.clear();
   string copy=s;
   allasort(copy);
   if(copy==s);
   break;
   }
   cout<<index<<endl;
   for(auto &i:v)
   printv(i);
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
stack,queue->no index access
use deque,vectors
-->assign(n,val)available for both
-->take size +1(extra) for vectors
*/
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
    


// bool check(vector<ll> &v)
// {
//     fr(i,v.size())
//     {
//     if(v[i]!=(i+1))
//     return false;
//     }
//     return true;
// }
void solve(){
   inp(n);
   vector<ll> v(n);
   inpv(v);
   //vector<ll> copy=v;
   //sort(copy.begin(),copy.end());
   fr(i,n)
   {
    if(i%2==0 && v[i]%2==0)
    {
        cout<<-1<<endl;
        return;
    }
    if(i%2!=0 && v[i]%2!=0)
    {
        cout<<-1<<endl;
        return;
    }
   }
   ll ct=0;
   vector<ll> odd,even;
   fr(i,n)
   {
    if(v[i]%2==0)
    even.pb(v[i]);
    else
    odd.pb(v[i]);
   }
//    printv(odd);
//    printv(even);
   
//    if(check(v))
//    {
//     cout<<0<<endl;
//     return;
//    }
if(is_sorted(all(v)))
{
    cout<<0<<endl;
    return;
}
   for(ll i=0;i<odd.size()-1;++i)
   {
    for(ll j=odd.size()-1;j>0;--j)
    {
        if(odd[j]<odd[j-1])
        {
            swap(odd[j],odd[j-1]);
            ct++;
        }
    }
   }
   for(ll i=0;i<even.size()-1;++i)
   {
    for(ll j=even.size()-1;j>0;--j)
    {
        if(even[j]<even[j-1])
        {
            swap(even[j],even[j-1]);
            ct++;
        }
    }
   }
   cout<<ct<<endl;
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
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
/// ------------------------------------PRE-DEFINED VALUES---------------------------------------- ///
#define maxval                1000000007
#define PI                    3.141592653589793238
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

    
    
void solve(){
    inp(a);
    inp(b);
    if(a%2!=0 && b%2!=0)
    cout<<"No"<<endl;
    else
    cout<<"Yes"<<endl;
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
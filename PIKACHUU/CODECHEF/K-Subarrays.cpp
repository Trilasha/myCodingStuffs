/// ------------------------------------------------------------------------------------------------- ///
///////// SUCCESS IS NOT FINAL,FAILURE IS NOT FATAL. IT IS THE COURAGE TO CONTINUE THAT COUNTS //////////
/// ------------------------------------------------------------------------------------------------- ///
    
    
/// ------------------------------------HEADER-FILES and ABBREVIATIONS---------------------------- ///
#include <bits/stdc++.h>


using namespace std;


#define ll                   long long
#define ld                   long double
#define pb                   push_back
#define popb                 pop_back
#define lb                   lower_bound
#define up                   upper_bound
#define umap                 unordered_map
#define uset                 unordered_set
/// ------------------------------------PRE-DEFINED VALUES---------------------------------------- ///
#define maxval               1000000007
#define PI                   3.141592653589793238
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
#define all                   str.begin(), str.end()
    
    
    
void solve(){

   

 ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    inpv(v);

    ll g=0;
    //sort(all(v));
    map<ll,ll> mp;

    for(ll i=0;i<n;i++) g= __gcd(g,v[i]), mp[v[i]]++;
   // cout<<g<<" ";

   if(g>1){
        if(mp[g]>=k){
            cout<<"YES"<<endl;
            return;
        }
        cout<<"NO"<<endl;
        return;
   }
   ll ct=0;
   ll x=0;
   for(ll i=0;i<n;i++){
     if(x==1){
       ct++;
       x=0;
     }
     x= __gcd(x,v[i]);
   }
   if(x==1){
       ct++;
       x=0;
     }
    if(ct>=k){
        cout<<"YES"<<endl;
        return;
    }

    cout<<"NO"<<endl;


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
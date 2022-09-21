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
    inp(n);
    //considering water defeat first
    //max pokemon that can be defeated(toto)= n-1
    vector<ll> gr(n),wt(n);
    inpv(gr);inpv(wt);
    vector<pair<ll,ll>> vp;
    fr(i,n)
    vp.pb({wt[i],gr[i]});
    allasort(vp);

    //
    vector<ll> v(n);
    v[n-1]=vp[n-1].second;
    ll temp=max(vp[n-1].second,vp[n-2].second);
    for (ll i = n-2; i>=0; --i)
    {
    //cout<<temp<<endl;
       v[i]=temp;
       if(i!=0)
       temp=max(temp,vp[i-1].second);
    }
    // for(auto &i:v)
    // cout<<i<<" ";
    // cout<<endl;
    //
    ll ans=1;
    fr(i,n-1)
    {
    if(v[i]>v[i+1])
    ans++;
    }

    cout<<ans<<endl;



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
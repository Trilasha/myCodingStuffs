/// ------------------------------------------------------------------------------------------------- ///
///////// SUCCESS IS NOT FINAL,FAILURE IS NOT FATAL. IT IS THE COURAGE TO CONTINUE THAT COUNTS //////////
/// ------------------------------------------------------------------------------------------------- ///
    
    
/// ------------------------------------HEADER-FILES and ABBREVIATIONS---------------------------- ///
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define popb pop_back
#define lb lower_bound
#define up upper_bound
#define umap          unordered_map
#define uset          unordered_set
/// ------------------------------------PRE-DEFINED VALUES---------------------------------------- ///
#define maxval                  1000000007
#define PI          3.141592653589793238
/// ------------------------------------TAKING INPUTS--------------------------------------------- ///
#define inp(n)              ll n;cin>>n;
#define inpv(v)              for(auto &x: v) cin>>x;
#define make(arr,n)   ll arr[n]; fr(i,n) cin>>arr[i];
/// ------------------------------------FOR LOOPS AND SORT---------------------------------------- ///
#define fr(i,n)             for (ll i=0;i<n;++i)
#define frs(i,k,n)            for(ll i=k;i<n;++i)
#define fA(i,a,n)   for(ll i=a;i<=(n);++i)
#define fD(i,a,n)   for(ll i=a;i>=(n);--i)
#define dsort(arr)            sort(arr,arr+n,greater<ll>())
#define asort(arr)            sort(arr,arr+n)
#define allasort(str)             sort(str.begin(), str.end())
#define alldsort(str)              sort(str.begin(), str.end(),greater<char>())
#define all            str.begin(), str.end()
    
    
    
using namespace std;
void solve()
{
    inp(n);
    vector<ll> gr(n),wt(n);
    map<ll,ll> mp_gr;
    map<ll,ll> mp_wt;
    fr(i,n)
    {
        cin>>gr[i];
        mp_gr[gr[i]]=i+1;
    }
      fr(i,n)
    {
        cin>>wt[i];
        mp_wt[wt[i]]=i+1;
    }
    //
    map<ll,ll> po_gr;
    sort(gr.begin(),gr.end());
    fr(i,n)
    {
        po_gr[gr[i]]=i;
    }
     map<ll,ll> po_wt;
    sort(wt.begin(),wt.end());
    fr(i,n)
    {
        po_wt[wt[i]]=i;
    }
    //
    map<ll,ll> ans_gr;
    map<ll,ll> ans_wt;
   for(auto &i:mp_gr)
   {
    ans_gr[i.second]=po_gr[i.first];
   }
   for(auto &i:mp_wt)
   {
    ans_wt[i.second]=po_wt[i.first];
   }
   //
   vector<ll> ans;
   for(auto &i:ans_gr)
   {
    ans.pb(i.second+ans_wt[i.first]);
   }
   sort(ans.begin(),ans.end(),greater<ll>());
   map<ll,ll> last;
   fr(i,n)
   {
    last[ans[i]]++;
   }
   cout<<last[ans[0]]<<endl;
}
    
int main()
{
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
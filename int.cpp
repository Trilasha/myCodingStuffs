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
#define all(str)           str.begin(), str.end()
    
    
    
using namespace std;
ll binarysearch(vector<ll> &v,ll k)
{
    ll left=0;
    ll right=v.size()-1;
    ll mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(v[mid]<k)
        left=mid+1;
        else if(v[mid]>k)
        right=mid-1;
        else if(v[mid]==k)
        return mid;
    }
    return -1;
}
void insert(stack<ll> &s,ll temp)
{
    if(s.empty() || s.top()<=temp)
    {
        s.push(temp);
        return;
    }
    ll var=s.top();
    s.pop();
    insert(s,temp);
    s.push(var);
    return;
}
void sorting(stack<ll> &s,ll n)
{
    if(s.size()==1)
    return;
    ll temp=s.top();
    s.pop();
    sorting(s,n);
    insert(s,temp);
    return;
}
void solve()
{
    ll n;
    cin>>n;
    // ll k;
    // cin>>k;
    vector<ll> v(n);
    for(ll i=0;i<n;++i)
    cin>>v[i];
   stack<ll> s;
   for(ll i=0;i<v.size();++i)
   s.push(v[i]);
   sorting(s,v.size());
   

   stack<ll> output=s;
   for(ll i=0;i<n;++i)
   {
    cout<<output.top()<<" ";
    output.pop();
   }
   cout<<endl;

    //ll ans=binarysearch(v,k);
   // cout<<ans<<endl;
}
    
int main()
{
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
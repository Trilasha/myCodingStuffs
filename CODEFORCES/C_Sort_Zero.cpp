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
#define ub                   upper_bound
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
#define all(str)              str.begin(), str.end()
#define pll                   pair<ll,ll>

    
    
void solve(){
    inp(n);
    vector<ll> v(n);
    inpv(v);
    map<ll,ll> mp;
    fr(i,n)
    {
        mp[v[i]]++;
    }
    set<ll> s;
    ll index=-1;
    ll set=0;
    ll ct=0;
    for(ll i=n-1;i>0;--i)
    {
         mp[v[i]]--;
        if(v[i-1]>v[i])
        {
            index=i-1;
            set=1;
            break;
        }
        else if(v[i-1]<v[i])
        {
            if(mp[v[i]]==0)
            continue;
            else
            {
                index=i-1;
                set=1;
               break;
            }
        }
       

    }
    if(set==1)
    {
    for(ll i=0;i<=index;++i)
    {
        if(s.find(v[i])==s.end())
        ct++;
        s.insert(v[i]);
    }
    }
    cout<<ct<<endl;
    return;
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
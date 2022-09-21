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
     string s;
    cin>>s;
    ll indo=s[0]-'a';
    ll indl=s[s.size()-1]-'a';
    vector<ll> ans;
    ans.pb(1);
    vector<vector<ll>> v(26);
    for(ll i=1;i<s.size()-1;++i)
    {
        v[s[i]-'a'].pb(i+1);
    }
    if(s[0]>=s[s.size()-1])
    {
        sort(s.begin()+1,s.end()-1,greater<char>());
    }
    else if(s[0]<s[s.size()-1])
    {
         sort(s.begin()+1,s.end()-1);
    }
    for(ll i=1;i<s.size()-1;++i)
    {
        if(s[i]-'a'>=min(indo,indl) && s[i]-'a'<=max(indl,indo))
        {
        ans.pb(v[s[i]-'a'][0]);
        v[s[i]-'a'].erase(v[s[i]-'a'].begin());
        }
    }
    ans.pb(s.size());
    cout<<abs(indl-indo)<<" "<<ans.size()<<endl;
    for(auto &i:ans)
    cout<<i<<" ";
    cout<<endl;
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
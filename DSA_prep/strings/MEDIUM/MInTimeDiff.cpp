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
    int findMinDifference(vector<string>& timePoints) {
        vector<int> v;
        for(auto &i:timePoints)
        {
            string ans;
            string hour;
            hour.push_back(i[0]);
            hour.push_back(i[1]);
            if(hour=="00")
                hour="24";
            int hrtomin=stoi(hour)*60;
            ans.push_back(i[3]);
            ans.push_back(i[4]);
            if(ans=="00")
                ans="60";
            int num=stoi(ans)+hrtomin;
            v.push_back(num);
        }
        sort(v.begin(),v.end());
        int diff=INT_MAX;
        for(int i=1;i<v.size();++i)
        {
            diff=min(diff,v[i]-v[i-1]);
        }
        return diff;
    }
    
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n;
    cin>>n;
    vector<string> v;
    fr(i,n)
    {
        string s;
        cin>>s;
        v.pb(s);
    }
    cout<<findMinDifference(v)<<endl;
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define md                  10000007
#define fr(i,n)             for (ll i=0;i<n;++i)
#define fr1(i,k,n)            for(ll i=k;i<n;++i)
#define dsort(arr)            sort(arr,arr+n,greater<ll>())
#define asort(arr)            sort(arr,arr+n)
#define allasort(str)             sort(str.begin(), str.end())
#define alldsort(str)              sort(str.begin(), str.end(),greater<char>())
#define all            str.begin(), str.end()
#define lb lower_bound
#define up upper_bound
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    ll q;
    cin>>q;
    while (q--)
    {
        ll n;
        cin>>n;
        map<ll,ll> mp;
        for (ll i = 0; i < n; ++i)
        {
            ll x;
            cin>>x;
            mp[x]++;
        }
        ll c=0;
       for(auto i:mp)
       {
           if(i.second>=3)
           {
               cout<<i.first<<endl;
               c=1;
               break;
           }
       }
        if(c==0)
        cout<<-1<<endl;
        
    }
    
    return 0;
}
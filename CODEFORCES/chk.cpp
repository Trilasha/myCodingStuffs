#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    vector<int> costs={1,3,2,4,1};
    int coins=7;
  int sz=costs.size();
       sort(costs.begin(),costs.end());
       vector<int> pref(sz);
       pref[0]=costs[0];
       for(int x=1;x<sz;++x)
       pref[x]=pref[x-1]+costs[x];

        int index=lower_bound(pref.begin(),pref.end(),coins)-pref.begin();
        int temp=index+1;

        for(auto &i:pref)
        cout<<i<<" ";
        cout<<endl;
        cout<<index<<endl;
       // cout<<pref.size();
        cout<<pref[index];
    return 0;
}
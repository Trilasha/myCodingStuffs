#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll check(ll mid,ll n,vector<int> &burstTime){
    if(mid<burstTime[0]) return 0;
    ll cnt=1;
    ll curr=0;
    ll nn=burstTime.size();
    for(ll i=0;i<nn;++i){
        curr+=burstTime[i];
        if(curr>mid){
            curr=burstTime[i];
            cnt++;
        }
    }
    return (cnt<=n);
}
ll func(int n,vector<int> &burstTime){
    ll low=0;
    ll high=1e16;
    ll ans=1e16;
    while(low<=high){
        ll mid=(low+high)/2;
        if(check(mid,n,burstTime)){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> burstTime(m);
    for(int i=0;i<m;++i){
        cin>>burstTime[i];
    }
    //  for(auto &i:burstTime){
    //     cout<<i<<" ";
    // }
    cout<<func(n,burstTime)<<endl;
    return 0;
}
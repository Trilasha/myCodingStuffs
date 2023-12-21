#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define fast_io               ios_base::sync_with_stdio(false);cin.tie(NULL);
/*-----------------------------------------------------------------------------------------------------------*/




void solitude(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(auto &i:v)cin>>i;
    vector<vector<ll>> store(n+2,vector<ll>(32));
    for(ll i=0;i<31;++i){
        for(ll j=0;j<n;++j){
            store[j+1][i]=store[j][i]+((v[j]&(1<<i))&&1);
        }
    }
    ll q;
    cin>>q;
    ll l,k;
    function<bool(ll)> check=[&](ll mid){
        ll val=0;
        for(ll i=0;i<31;++i){
            if((store[mid][i]-store[l-1][i])==mid-l+1){
                val+=(1<<i);
            }
        }
        // cout<<val<<endl;
        return val>=k;
    };

    while(q--){
        cin>>l>>k;
        ll low=l;
        ll high=n;
        ll ans=-1;
        while(low<=high){
            ll mid=(low+high)/2;
            if(check(mid)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        cout<<ans<<" ";
    }
    cout<<endl;
}

int main(){

fast_io;

ll q=1;
cin>>q;
for(ll i=0;i<q;i++){
    solitude();
}
    return 0;   
}
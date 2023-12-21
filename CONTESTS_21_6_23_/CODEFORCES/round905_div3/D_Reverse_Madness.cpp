#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define fast_io               ios_base::sync_with_stdio(false);cin.tie(NULL);
/*-----------------------------------------------------------------------------------------------------------*/




void solitude(){
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    map<ll,ll> mp;
    vector<ll> l(k),r(k);
    for(auto &i:l)cin>>i;
    for(auto &i:r)cin>>i;
    ll q;
    cin>>q;
    vector<ll> x(q);
    for(auto &i:x)cin>>i;
    sort(x.begin(),x.end());
    // for(auto &i:x)cout<<i<<" ";
    // cout<<endl;
    ll ind=0;
    ll st=l[0];
    ll end=r[0];
    ll mid=(l[0]+r[0])/2;
    for(ll i=0;i<q;++i){
        while(ind<k && r[ind]<x[i]){
            ll cnt=0;
            for(ll j=st;j<=mid;++j){
                if((mp[j]+cnt)%2){
                    ll v1=j-1;
                    ll v2=end-(j-st)-1;
                    swap(s[v1],s[v2]);
                }
                cnt+=mp[j];
              }
            //cout<<s<<endl;
            mp.clear();
            ind++;
            if(ind<k){
                st=l[ind];
                end=r[ind];
                mid=(l[ind]+r[ind])/2;
            }
        }
        // cout<<s<<endl;
        if(x[i]<=mid){
            mp[x[i]]++;
        }else{
            mp[st+end-x[i]]++;
        }
    }
    ll cnt=0;
    for(ll j=st;j<=mid;++j){
    // cout<<j<<" "<<mp[j]<<endl;
        if((mp[j]+cnt)%2){
            ll v1=j-1;
            ll v2=end-(j-st)-1;
            swap(s[v1],s[v2]);
        }
        cnt+=mp[j];
    }
    cout<<s<<endl;
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
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define fast_io               ios_base::sync_with_stdio(false);cin.tie(NULL);
/*-----------------------------------------------------------------------------------------------------------*/




void solitude(){
    ll n,a,b,k;
    cin>>n>>a>>b>>k;
    vector<ll> v(n);
    for(auto &i:v)cin>>i;
    ll cnt=0;
    vector<ll> temp;
    for(ll i=0;i<n;++i){
        ll div=v[i]/(a+b);
        ll rem=v[i]%(a+b);
        if(rem==0){
            temp.push_back(b);
        }else{
            if(rem<=a)cnt++;
            else temp.push_back(rem-a);
        }
    }
    sort(temp.begin(),temp.end());
    for(ll i=0;i<temp.size();++i){
        if(k==0)break;
        ll req=(temp[i]+a-1)/a;
        if(k>=req){
            cnt++;
            k-=req;
        }else break;
    }
    cout<<cnt<<endl;
}

int main(){

fast_io;

ll q=1;
// cin>>q;
for(ll i=0;i<q;i++){
    solitude();
}
    return 0;   
}
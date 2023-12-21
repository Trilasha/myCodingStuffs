#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define fast_io               ios_base::sync_with_stdio(false);cin.tie(NULL);
/*-----------------------------------------------------------------------------------------------------------*/




void solitude(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll> v(26),temp;
    for(ll i=0;i<n;++i){
        ll val=s[i]-'a';
        for(ll j=val+1;j<=25;++j){
            v[val]=max(v[val],v[j]+1);
        }
        v[val]=max(v[val],1LL);
        // cout<<v[val]<<" ";
        temp.push_back(v[val]);
    }
    ll mx=*max_element(temp.begin(),temp.end());
    if(mx>2){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    for(ll i=0;i<n;++i){
        cout<<temp[i]-1;
    }
    cout<<endl;
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
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
    ll o=0,e=0;
    for(auto &i:v){
        if(i%2)o++;
        else e++;
    }
    if(o==0){
        cout<<"NO"<<endl;
        return;
    }
    if(e==0){
        cout<<((n%2)?"YES":"NO")<<endl;
        return;
    }
    cout<<"YES"<<endl;
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
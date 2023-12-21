#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define fast_io               ios_base::sync_with_stdio(false);cin.tie(NULL);
/*-----------------------------------------------------------------------------------------------------------*/




void solitude(){
    ll n;
    cin>>n;
    ll ans=0;
    while(n>=10){
        ll div=n/10;
        // ll rem=n%10;
        ans+=10*div;
        n-=(div*10);
        n+=div;
    }
    ans+=n;
    cout<<ans<<endl;
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
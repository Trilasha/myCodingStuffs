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
    map<pair<ll,ll>,ll> mp;
    ll x=0,y=0;
    ll ans=n+1;
    ll ok=0;
    pair<ll,ll> p1;
    mp[{0,0}]=0;
    for(ll i=0;i<n;++i){
        if(s[i]=='L')x--;
        else if(s[i]=='R')x++;
        else if(s[i]=='U')y++;
        else y--;
        if(mp.count({x,y})){
            ok=1;
            ll curr=i-mp[{x,y}];
            if(curr<ans){
                ans=curr;
                p1=make_pair(mp[{x,y}]+1,i+1);
            }
        }
        mp[{x,y}]=i+1;
    }
    if(!ok && x==0 && y==0){
        cout<<1<<" "<<n<<endl;
        return;
    }
    if(!ok){
        cout<<-1<<endl;
        return;
    }
    cout<<p1.first<<" "<<p1.second<<endl;

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
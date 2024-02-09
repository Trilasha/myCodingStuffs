#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_io               ios_base::sync_with_stdio(false);cin.tie(NULL);       
void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;++i){
        cin>>v[i];
    }
    sort(v.begin(),v.end(),greater<ll>());
    ll cnt=0;
    ll x=-1;
    for(ll i=0;i<n;++i){
        if(v[i]==1){
            cnt=n-i;
            if(x==-1){
                if(cnt%2){
                    cout<<"ALICE"<<endl;
                }else{
                    cout<<"BOB"<<endl;
                }
                return;
            }
            if(x==0){
                if(cnt%2){
                    cout<<"BOB"<<endl;
                }else{
                    cout<<"ALICE"<<endl;
                }
                return;
            }
            if(cnt%2){
                cout<<"ALICE"<<endl;
            }else{
                cout<<"BOB"<<endl;
            }
            return;
        }
        if((v[i]%3)==1){
            x=0;
        }else{
            x=1;
        }
    }

 
}

int main(){

fast_io;
ll q=1;
cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}


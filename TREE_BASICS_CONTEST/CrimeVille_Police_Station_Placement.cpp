#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                " \n"
#define F                   first
#define S                   second
#define sz(x)               (int)(x).size()   
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end()
#define rep(i, a, b)        for (int i = a; i < (b); ++i)
#define fast_io             cin.tie(0)->sync_with_stdio(0);cin.exceptions(cin.failbit);

using ll  = long long;
using ull = unsigned long long;
using lld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vl  = vector<ll>;
using vi  = vector<int>;


void dk(){
      ll n,k;
      cin>>n>>k;
      vl v(n);
      inp(v);
      sort(all(v));

      auto check=[&](ll x)->bool{
            ll left=0,right=0;
            ll ct=0;
           if((v[1]-v[0])>x){
            left=v[0]+x,right=left;
            ct=0;
            for(int i=1;i<n;i++){
                if(v[i]>right){
                        ct++;
                        left=v[i]+x;
                        right=v[i]+x;
                }
            }
           }else{
            left=v[1]-x,right=v[1]+x;
            ct=0;
           for(int i=2;i<n;i++){
               if(v[i]>right){
                    ct++;
                    left=v[i]+x;
                    right=v[i]+x;
               }

           }
           }
           return ct<=k;
      };
      ll l=0,r=1e15;
      ll ans=0;
      while(l<=r){
           ll mid=(l+r)/2;
           if(check(mid)){
            ans=mid;
            r=mid-1;
           }
           else l=mid+1;
      }
     cout<<l<<endl;
}



int main()
{ 
    fast_io;
    
    int _=1;
    cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   
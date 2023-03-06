#include <bits/stdc++.h>
using namespace std;
#include<string>
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define fr(i,a,b) for(int i = a; i < b; i++)
#define mod (ll)(1e9+7)
typedef int long long ll; 
#define inf 1000000000
int main()
{
      int t ; cin >> t;
      while(t--){
        ll n ,c=0,ans=0; cin >> n ;
       map <ll,ll> m;
       fr(i,0,n){
          cin >> c;
          c^=(i+1);
          m[c]++;
       }
       for(auto i:m){
          ans+=(i.second*(i.second-1))/2;
          
       }
        cout << ans<< endl;
         
        
      }
   return 0;
}  
   
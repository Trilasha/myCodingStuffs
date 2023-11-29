/* Trilasha Mazumder */


#include <bits/stdc++.h>
using namespace std;
           
#define ll                    long long
#define ld                    long double
#define pb                    push_back
#define lb                    lower_bound
#define ub                    upper_bound
#define ff                    first
#define ss                    second
#define maxpq                 priority_queue <ll> pq;
#define minpq                 priority_queue <ll, vector<ll>, greater<ll> > pq; 
#define inpv(v)               for(auto &x: v) cin>>x;
#define fr(i,n)               for (ll i=0;i<n;++i)
#define all(str)              str.begin(), str.end()
#define pll                   pair<ll,ll>
#define printv(v)             for(auto &i: v){cout << i << " ";} cout << endl;
#define printmap(mp)          for(auto &i: mp){cout << i.first << " "<<i.second<<endl;}
#define printset(st)          for(auto &i: st){cout << i << " ";} cout << endl;
#define line                  cout<<"----------------------------------------"<<endl;
#define arrow                 cout<<"--->";
#define debugmap(mp)          for(auto &i: mp){cout << i.ff << "-->" << i.ss <<endl;} cout << endl;
#define debugset(st)          for(auto &i: st){cout << i << " ";} cout << endl;
#define fast_io               ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sp(x)                 fixed<<setprecision(x)
#define PI                    3.141592653589793238
#define bpl(n)                __builtin_popcountll(n);
#define md                    998244353
#define modval                1000000007
//#define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- */







void solve(){
     int n;
     cin>>n;
     string a,b;
     cin>>a>>b;
     string temp=a;
     a=b;
     b=temp;
     if(a==b){
          cout<<n*(n+1)/2<<endl;
          return;
     }
     vector<ll> blocks;
     int ct=0;
     for(int i=0;i<n;i++){
          if(a[i]==b[i]){
               if(ct) blocks.pb(ct);
               ct=0;
          }
          else{
               ct++;
          }
     }
     if(ct){
          blocks.pb(ct);
     }
     if(blocks.size()>2){
          cout<<0<<endl;
          return;
     }
     if(blocks.size()==1){
          if(n==1){
               cout<<0<<endl;
               return;
          }
          int ind=0,ct=0;;
          for(int i=0;i<n;i++){
               if(a[i]!=b[i]){
                    ind=i;
                    break;
               }
               ct++;
          }
          for(int i=ind;i<n;i++){
               if(a[i]==b[i]){
                    ind=i;
                    break;
               }
          }
          for(int i=ind;i<n;i++){
               if(a[i]!=b[i]) continue;
               ct++;
          }
          cout<<2*(blocks[0]-1+ct)<<endl;
          return;
     }
     cout<<6<<endl;
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


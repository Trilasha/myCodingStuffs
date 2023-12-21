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
   ll n;
   cin>>n;
   n--;
   vector<ll> v(n);
   inpv(v);
   ll sum=((n+1)*(n+2))/2;
   ll curr=0;
   ll mid=(n/2)-1;
   for(ll i=mid;i>=0;--i){
        curr+=(-v[i])*(i+1);
   }
//    cout<<curr<<endl;
   for(ll i=mid+1;i<n;++i){
        curr+=v[i]*(n-i);
   }
//    cout<<curr<<endl;
   ll rem=sum-curr;
   ll x=rem/(n+1);
   if(rem<=0 || x==0){
        cout<<-1<<endl;
        return;
   }
    // cout<<rem<<endl;
   cout<<sum<<" "<<curr<<" "<<x<<endl;
   vector<ll> ans(n+1);
   ans[n/2]=x;
   ll ind=(n/2)-1;
   for(ll i=mid;i>=0;--i){
        ans[ind]=ans[ind+1]-v[i];
        ind--;
   }
   ind=(n/2)+1;
   for(ll i=mid+1;i<n;++i){
        ans[ind]=ans[ind-1]+v[i];
        ind++;
   }
   vector<ll> temp=ans;
//    sort(all(temp));
//    fr(i,n+1){
//      if(temp[i]!=i+1){
//           cout<<-1<<endl;
//           return;
//      }
//    }
   printv(ans);

}


int main(){

fast_io;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

ll q=1;
// cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}

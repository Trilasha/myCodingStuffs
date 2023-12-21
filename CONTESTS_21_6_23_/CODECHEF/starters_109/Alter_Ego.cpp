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
   vector<ll> v(n);
   inpv(v);
   vector<ll> odd,even;
   sort(all(v));
   for(auto &i:v){
    if(i%2){
        odd.pb(i);
    }else{
        even.pb(i);
    }
   }
   if((odd.size()%2 || even.size()%2)){
    cout<<-1<<endl;
    return;
   }
//    line
   vector<ll> ans(n);
   sort(all(odd));
   sort(all(even));
   vector<ll> O(odd.size()),E(even.size());
   ll ind=0;
   for(auto &i:odd){
    O[ind]=i;
    ind+=2;
    if(ind>=odd.size())ind=1;
   }
   ind=0;
   for(auto &i:even){
    E[ind]=i;
    ind+=2;
    if(ind>=even.size())ind=1;
   }
   ind=0;
   for(ll i=0;i<odd.size();i+=2){
    ll add=(O[i+1]+O[i])/2;
    ll sub=(O[i+1]-O[i])/2;
    ans[ind]=add;
    ans[ind+n/2]=sub;
    ind++;
   }
   for(ll i=0;i<even.size();i+=2){
    ll add=(E[i+1]+E[i])/2;
    ll sub=(E[i+1]-E[i])/2;
    ans[ind]=add;
    ans[ind+n/2]=sub;
    ind++;
   }
   printv(ans);
}


int main(){

fast_io;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

ll q=1;
cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}


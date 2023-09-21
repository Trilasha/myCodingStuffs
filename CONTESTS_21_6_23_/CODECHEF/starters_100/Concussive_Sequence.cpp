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
 sort(all(v));
 ll half=(n+1)/2;
 ll ind=0;
 vector<ll> ans,ans2;
 while(ans.size()<n){
    if(ind<(n+1)/2)
    ans.pb(v[ind]);
    ind++;
    if(half<n)
    ans.pb(v[half]);
    half++;
 }
 ind=0;
 half=n/2;
    while(ans2.size()<n){
        if(half<n)
        ans2.pb(v[half]);
        half++;
        if(ind<(n)/2)
        ans2.pb(v[ind]);
        ind++;
    }
 ll ok=0;
 ll nn=0;
 for(ll i=0;i<n-2;++i){
    if(ans[i]<ans[i+1] && ans[i+1]>ans[i+2] && !ok){
        ok=1;
        continue;
    }
    if(ans[i]>ans[i+1] && ans[i+1]<ans[i+2] && ok){
        ok=0;
        continue;
    }
    // cout<<"-1"<<endl;
    // return;
    nn=1;
    break;
 }
 if(nn==0){
    printv(ans);
    return;
 }

 ok=0;
 nn=0;
 for(ll i=0;i<n-2;++i){
    if(ans2[i]>ans2[i+1] && ans2[i+1]<ans2[i+2] && !ok){
        ok=1;
        continue;
    }
    if(ans2[i]<ans2[i+1] && ans2[i+1]>ans2[i+2] && ok){
        ok=0;
        continue;
    }
    nn=1;
    break;
 }
 if(nn==0){
    printv(ans2);
    return;
 }

 cout<<-1<<endl;
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


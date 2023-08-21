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



ll n;
vector<ll> v;
vector<vector<ll>> dp;

ll recur(ll left,ll right){
    if(left>right) return 0;
    if(left==right) return 1;
    if(dp[left][right]!=INT_MAX) return dp[left][right];
    ll ans=1+recur(left+1,right);
    for(ll i=left+2;i<=right;++i){
        if(v[left]==v[i]){
            ans=min(ans,recur(left+1,i-1)+recur(i+1,right));
        }
    }
    if(left<n-1 && v[left]==v[left+1]){
        ans=min(ans,1+recur(left+2,right));
    }
    return dp[left][right]=ans;
}
void solve(){
    cin>>n;
    v.resize(n);
    inpv(v);
    dp.assign(n+1,vector<ll>(n+1,INT_MAX));
    cout<<recur(0,n-1)<<endl;
}


int main(){

fast_io;

ll q=1;
//cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}









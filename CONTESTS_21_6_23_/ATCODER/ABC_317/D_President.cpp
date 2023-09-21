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



// taka aoki z
vector<vector<ll>> dp;
ll recur(ll ind,ll currSum,vector<vector<ll>> &v){
    if(currSum<=0) return 0;
    // if(ind==v.size()){
    //     if(currSum<=0) return 0;
    //     return INT_MAX;
    // }
    if(ind>=v.size()) return INT_MAX;
    if(dp[ind][currSum]!=INT_MAX) return dp[ind][currSum];
    ll req=v[ind][0]+v[ind][1];
    req=(req/2)+1;
    ll pick=max(0ll,req-v[ind][0]) + recur(ind+1,currSum-v[ind][2],v);
    ll notPick=recur(ind+1,currSum,v);
    return dp[ind][currSum]=min(pick,notPick);
}
void solve(){
    ll n;
    cin>>n;
    vector<vector<ll>> v(n,vector<ll>(3,0));
    ll sum=0;

    fr(i,n){
        ll x,y,z;
        cin>>x>>y>>z;
        v[i][0]=x;v[i][1]=y;v[i][2]=z;
        sum+=z;
    }
    sum=(sum/2)+1;
    dp.resize(n+1,vector<ll>(sum+4,INT_MAX));
    cout<<recur(0,sum,v)<<endl;
    

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





/*  
    Aisa Mera Dil Kabhi Na Tha
    Hairaan Be-Wajah
    Saughat Teri Hai Yeh...
        Bas Ek Baar Tumko... Dekhne Ko Tarsun...
        Kehta Hai Dil Yeh Mera... 
*/


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






ll recur(ll ind,ll mask,ll req,vector<vector<ll>> &dp,vector<vector<ll>> &v){
    if(ind==req/2){
        return 0;
    }
    if(dp[ind][mask]!=-1) return dp[ind][mask];
    ll ans=0;
    for(ll i=1;i<=req;++i){
        if(mask&(1<<i)) continue;
        for(ll j=1;j<=req;++j){
            if(mask&(1<<j)) continue;
            ans=max(ans,v[i][j]+recur(ind+1,mask|(1<<i)|(1<<j),req,dp,v));
        }
    }
    return dp[ind][mask]=ans;
}
void solve(){
    ll n;
    cin>>n;
    vector<vector<ll>> v(n+1,vector<ll>(n+1));
    for(ll i=1;i<n;++i){
        ll ind=i+1;
        for(ll j=1;j<=n-i;++j){
           ll x;
           cin>>x;
           v[i][ind]=x;
           v[ind][i]=x;
           ind++;
        }
    }
    // for(ll i=0;i<=n;++i){
    //     cout<<i<<"--->";
    //     printv(v[i]);
    // }
    vector<vector<ll>> dp(n+1,vector<ll>(1<<n+1,-1));
    cout<<recur(0,0,n,dp,v)<<endl;
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


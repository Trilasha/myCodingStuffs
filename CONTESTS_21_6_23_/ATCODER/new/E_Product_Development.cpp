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




ll recur(ll ind,vector<ll> temp,ll m,ll P,vector<vector<ll>> &v,map<ll,map<vector<ll>,ll>> &dp){
    if(ind==v.size()){
        for(ll i=0;i<m;++i){
            if(temp[i]<P) return 1e16;
        }
        return 0;
    }
    if(dp[ind].count(temp)) return dp[ind][temp];
    ll ans=recur(ind+1,temp,m,P,v,dp);
    vector<ll> Temp=temp;
    for(ll i=0;i<m;++i){
        Temp[i]+=v[ind][i+1];
        Temp[i]=min(Temp[i],P);
    }
    // printv(temp);
    ans=min(ans,v[ind][0]+recur(ind+1,Temp,m,P,v,dp));
    return dp[ind][temp]=ans;
}
void solve(){
    ll n,m,P;
    cin>>n>>m>>P;
    vector<vector<ll>> v(n,vector<ll>(m+1));
    for(ll i=0;i<n;++i){
        for(ll j=0;j<=m;++j){
            cin>>v[i][j];
        }
    }
    map<ll,map<vector<ll>,ll>> dp;
    vector<ll> temp(m);
    ll ans=recur(0,temp,m,P,v,dp);
    cout<<((ans==1e16)?-1:ans)<<endl;
}


int main(){

fast_io;

ll q=1;
// cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}


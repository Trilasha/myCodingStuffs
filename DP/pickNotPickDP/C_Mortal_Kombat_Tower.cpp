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
// define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- */






vector<ll> v;
vector<vector<ll>> dp;

ll recur(ll ind,ll prev){
    ll n=v.size();
    if(ind==n-1){
        if(prev==0){
            if(v[ind]==0)return 0;
            else return 1;
        }else{
            return 0;
        }
    }
    if(ind>=n)return 0;

    if(dp[ind][prev]!=INT_MAX) return dp[ind][prev];

    ll ans=INT_MAX;

    if(prev==0){
        //friend's turn
        if(v[ind]==0){
            ans=min(ans,recur(ind+1,1));
            if(v[ind+1]==0)
                ans=min(ans,recur(ind+2,1));
            else
                ans=min(ans,1+recur(ind+2,1));

        }else{
            ans=min(ans,1+recur(ind+1,1));
            if(v[ind+1]==0)
                ans=min(ans,1+recur(ind+2,1));
            else
                ans=min(ans,2+recur(ind+2,1));
        }

    }else{
            ans=min(ans,recur(ind+1,0));
            ans=min(ans,recur(ind+2,0));
    }
    //cout<<ans<<endl;
    //line
    return dp[ind][prev]=ans;
}


void solve(){
    ll n;
    cin>>n;
    v.resize(n);
    inpv(v);
    dp.resize(n+1,vector<ll>(2,INT_MAX));
    cout<<recur(0,0)<<endl;
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











/*--------------------------------------------------------------------------------------------------------- 
   reference for sequence(NT) --> oeis.org
   log2(x)
   set.lower_bound(x)
   for mod division --> a/b use a*inverse(b) (don't divide simply)
   set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
   gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
   a+b=2⋅(a&b)+a⊕b
   a⊕b=¬(a&b)&(a∣b)
   --------------------------------------------------------------------------------------------------------- */
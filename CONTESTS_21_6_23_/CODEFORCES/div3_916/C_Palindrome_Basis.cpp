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





vector<ll> palindromes;
ll sz;
vector<vector<ll>> dp;
void store(){
    for(ll i=1;i<=40001;++i){
            string s=to_string(i);
            string temp=s;
            reverse(all(s));
            if(temp==s){
                palindromes.pb(i);
            }
    }
    sz=palindromes.size();
    dp.assign(sz+1,vector<ll>(40001,-1));
}
void solve(){
    ll n;
    cin>>n;
    // cout<<sz<<endl;
    function<ll(ll,ll)> recur=[&](ll ind,ll sum){
        if(sum==0) return 1LL;
        if(ind==sz) return 0LL;
        // if(palindromes[ind]>sum) return 0LL;
        if(dp[ind][sum]!=-1)return dp[ind][sum];
        ll ans=recur(ind+1,sum);
        if(sum>=palindromes[ind]){
            ans=(ans+recur(ind,sum-palindromes[ind]))%modval;
        }
        return dp[ind][sum]=ans;
    };
    cout<<recur(0,n)<<endl;
 
}


int main(){

fast_io;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

store();
ll q=1;
cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}


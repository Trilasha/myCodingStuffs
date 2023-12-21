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
#define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- */





ll mp[30010];
ll dp[30010][510];
ll mx=0,ori;
vector<ll> stones;

ll recur(ll ind,ll d){
    if(ind>mx || d>ori+245 || d<ori-245) return 0;
    if(dp[ind][d]!=-1) return dp[ind][d];
    ll ans=0;
    if(d-1>0 && ind+d-1<=30001){
        ans=max(ans,mp[ind+d-1]+recur(ind+d-1,d-1));
    }
    if(ind+d<=30001){
        ans=max(ans,mp[ind+d]+recur(ind+d,d));
    }
    if(ind+d+1<=30001){
        ans=max(ans,mp[ind+d+1]+recur(ind+d+1,d+1));
    }
    return dp[ind][d]=ans;
}

void solve(){
    ll n,d;
    cin>>n>>d;
    ori=d;
    stones.resize(n);
    memset(dp,-1,sizeof(dp));
    for(int x=0;x<n;++x){
        cin>>stones[x];
        mx=max(mx,stones[x]);
        mp[stones[x]]++;
    }
    cout<<mp[d]+recur(d,d)<<endl;
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

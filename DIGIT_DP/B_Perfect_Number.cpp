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






//binary search + digit dp
//considering k is as large as 1e18

ll dp[20][12][2];

ll recur(ll n,ll sum,ll tight,string &s){
    if(sum<0) return 0;
    // if(n==1){
    //     ll ubb=((tight)?(s[s.length()-n]-'0'):9);
    //     if(sum<=ubb)
    //         return 1;
    //     return 0;
    // }
    if(n==0){
        return (sum==0);
    }
    if(dp[n][sum][tight]!=-1)
        return dp[n][sum][tight];
    ll ans=0;
    ll ubb=((tight)?(s[s.length()-n]-'0'):9);
    for(ll i=0;i<=ubb;i++){
        ans+=recur(n-1,sum-i,tight&(i==ubb),s);
    }
    return dp[n][sum][tight]=ans;
}

void solve(){
    ll k;
    cin>>k;
    ll low=1;
    ll high=1e18;
    ll ans=0;

    while(low<=high){
        ll mid=(low+high)/2;
        //numbers <=mid having sum = 10;
        string s=to_string(mid);
        memset(dp,-1,sizeof(dp));
        ll count=recur(s.length(),10,1,s);
        if(count>=k){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<ans<<endl;
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


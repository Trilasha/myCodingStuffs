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






ll dp[20][20][2];

ll recur(string &s,ll n,ll cnt,bool tight){
    if(n==0){
        return (cnt<=3);
    }
    if(dp[n][cnt][tight]!=-1)
        return dp[n][cnt][tight];
    ll ans=0;
    ll ubb=((tight)?s[s.length()-n]-'0':9);

    for(ll dig=0;dig<=ubb;++dig){
        ans+=recur(s,n-1,((dig!=0)?cnt+1:cnt),tight&(dig==ubb));
    }
    return dp[n][cnt][tight]=ans;
}

void solve(){
    ll L,R;
    cin>>L>>R;
    L--;
    string l=to_string(L);
    string r=to_string(R);
    memset(dp,-1,sizeof(dp));
    ll fr=recur(r,r.length(),0,1);
    memset(dp,-1,sizeof(dp));
    ll fl=recur(l,l.length(),0,1);
    //cout<<fr<<" "<<fl<<endl;
    cout<<fr-fl<<endl;
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


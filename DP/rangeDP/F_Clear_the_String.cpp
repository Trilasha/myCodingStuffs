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
//clear adj and visited vector declared globally after each test case 
//if input newly taken then use 'resize' or else 'assign' (for dp and graphs)
//    BINARY SEARCH ~ 2-PNTS ~ DP 
//    reference for sequence(NT) --> oeis.org
//    log2(x)
//    set.lower_bound(x)
//    for mod division --> a/b use a*inverse(b) (don't divide simply)
//    set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
//    gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
//    a+b=2⋅(a&b)+a⊕bs
//    a⊕b=¬(a&b)&(a∣b)
/*----------------------------------------------------------------------------------------------------------- */

ll n;
string s,temp;
ll dp[501][501];

ll recur(ll L,ll R){
    if(L>R){
        return 0;
    }
    if(L==R){
        return 1;
    }
    if(dp[L][R]!=-1){
        return dp[L][R];
    }

    ll ans=0;
    //gen
    ans=recur(L+1,R)+1;
    
    for(ll x=L+1;x<=R;++x){
        if(temp[L]==temp[x]){
            ans=min(ans,recur(L+1,x-1)+recur(x,R));
            // if(ok){
            //     ans=min(ans,recur(L+1,x-1,0)+recur(x+1,R,0));
            //     ans=min(ans,recur(L+1,x-1,0)+recur(x,R,1));
            // }else{
            //     ans=min(ans,recur(L+1,x-1,0)+recur(x,R,1)+1);
            // }
        }
    }

    return dp[L][R]=ans;
}


void solve(){
    cin>>n;
    cin>>s;
    temp="";
    memset(dp,-1,sizeof(dp));
    for(ll x=0;x<n;++x){
        if(temp.size()==0 || temp.back()!=s[x]){
            temp+=s[x];
        }
    }
    cout<<recur(0,temp.size()-1)<<endl;


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






   

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






//range dp (pull)
//dp[i][j][2] --> dp[i][j][0] to make the subarray from i to j have the color c[i] (left)
//            --> dp[i][j][1] to make the subarray form i to j have the color c[j] (right)


//recursive
// const int N=1e7;
// int n;
// vector<int> v;
// int dp[5005][5005][2];
 
 
// int recur(int L,int R,int curr){
//     if(L>=n || R<0) return 0;
//     if(L>=R) return 0;
//     if(dp[L][R][curr]!=N)return dp[L][R][curr];
 
//     int ans=N;
    
//     if(curr==0){
//             ans=min(ans,recur(L+1,R,0)+1);
//             ans=min(ans,recur(L+1,R,1)+((v[L]==v[R])?0:1));
//     }else{
//             ans=min(ans,recur(L,R-1,1)+1);
//             ans=min(ans,recur(L,R-1,0)+((v[L]==v[R])?0:1));
//     }
 
//     return dp[L][R][curr]=ans;
// }
 
 
// void solve(){
//     cin>>n;
//     v.resize(n);
//     inpv(v);
//     v.resize(unique(all(v))-v.begin());
//     n=v.size();
//     fr(i,n+1){
//         fr(j,n+1){
//             dp[i][j][0]=N;
//             dp[i][j][1]=N;
//         }
//     }
//     //bug -> min of both the possibilities to be considered
//     cout<<min(recur(0,n-1,0),recur(0,n-1,1))<<endl;
// }
 

 
//iterative 

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    inpv(v);
    v.resize(unique(all(v))-v.begin());
    n=v.size();

    int dp[n+2][n+2][2];
    int N=1e9+7;
    fr(i,n+1){
        fr(j,n+1){
            dp[i][j][0]=N;
            dp[i][j][1]=N;
        }
    }

    fr(i,n+1){
        dp[i][i][0]=0;
        dp[i][i][1]=0;
    }

    for(int i=n-2;i>=0;--i){
        for(int j=i+1;j<n;++j){

            int add=1;
            dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][0]+add);

            if(v[i]==v[j])add=0;
            dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][1]+add);

            add=1;
            dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][1]+add);

            if(v[i]==v[j])add=0;
            dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][0]+add);
        }
    }

    cout<<min(dp[0][n-1][0],dp[0][n-1][1])<<endl;

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






   

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






#define ll long long
vector<vector<ll>>dp;
ll recur(vector<int>&A,ll i,ll j,ll val){
    if((j-i)<1) return dp[i][j]=0;
    if(dp[i][j]!=-1) return dp[i][j];
    ll ans=0;
    if(A[i]+A[i+1]==val){
        ans=max(ans,recur(A,i+2,j,val)+1);
    }
    if(A[j]+A[j-1]==val){
        ans=max(ans,recur(A,i,j-2,val)+1);
    }
    if(A[j]+A[i]==val){
         ans=max(ans,recur(A,i+1,j-1,val)+1);   
    }
    return dp[i][j]=ans;
}
int solution(vector<int> &A) {
    int n=A.size();
    if(n==1){
        return 0;
    }
    ll ans=0;
    dp.assign(n+1,vector<ll>(n+1,-1));
    ans=recur(A,0,n-1,A[0]+A[1]);

    dp.assign(n+1,vector<ll>(n+1,-1));
    ans=max(ans,recur(A,0,n-1,A[0]+A[n-1]));

    dp.assign(n+1,vector<ll>(n+1,-1));
    ans=max(ans,recur(A,0,n-1,A[n-1]+A[n-2]));
    return ans;
}

void solve(){
    int N;
    cin>>N;
    int A[N];
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    cout<<solution(A,N)<<endl;
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


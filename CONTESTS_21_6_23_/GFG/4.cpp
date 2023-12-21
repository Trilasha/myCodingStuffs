#define ll long long 
#define mod 1000000007

class Solution {
  public:
    ll recur(ll ind,ll last,ll secondLast,ll flag,string &S,ll N,vector<vector<vector<vector<ll>>>>&dp){
        if(ind==N){
            return flag;
        }
        if(dp[ind][last][secondLast][flag]!=-1) return dp[ind][last][secondLast][flag];
        ll curr=S[ind]-'a';
        if(flag)curr=0;
        ll ans=0;
        for(ll x=curr;x<=25;++x){
            if(x==last || x==secondLast) continue;
            ans=(ans+recur(ind+1,x,last,flag|(x>curr),S,N,dp))%mod;
        }
        return dp[ind][last][secondLast][flag]=ans;
    }
    int specialStrings(int N, string S) {
        vector<vector<vector<vector<ll>>>> dp(N+1,vector<vector<vector<ll>>>(27,vector<vector<ll>>(27,vector<ll>(2,-1))));
        return recur(0,26,26,0,S,N,dp);
    }
};
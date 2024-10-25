//(number * 10 + i) % k --> divisibilty check
#define ll long long 

class Solution {
public:
    ll dp[15][15][15][2][24][2];
    ll recur(ll pos,ll evenCnt,ll oddCnt,bool leading,ll num,bool tight,string &s,int k){
        if(pos>=s.length()){
            if(evenCnt==oddCnt && !leading && num==0){
                return 1;
            }
            return 0;
        }
        if(dp[pos][evenCnt][oddCnt][leading][num][tight]!=-1)
            return dp[pos][evenCnt][oddCnt][leading][num][tight];

        ll ans=0;
        ll ub=((tight)?s[pos]-'0':9);
        for(ll dig=0;dig<=ub;++dig){
            if(dig==0 && leading){
                ans+=recur(pos+1,evenCnt,oddCnt,leading,num,tight&(dig==ub),s,k);
            }else if(dig%2){
                ans+=recur(pos+1,evenCnt,oddCnt+1,0,(num*10+dig)%k,tight&(dig==ub),s,k);
            }else if(dig%2==0){
                ans+=recur(pos+1,evenCnt+1,oddCnt,0,(num*10+dig)%k,tight&(dig==ub),s,k);
            }
        }
        return dp[pos][evenCnt][oddCnt][leading][num][tight]=ans;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        low--;
        string l=to_string(low);
        string r=to_string(high);
        memset(dp,-1,sizeof(dp));

        //
        ll fr=recur(0,0,0,1,0,1,r,k);
        memset(dp,-1,sizeof(dp));
        //
        ll fl=recur(0,0,0,1,0,1,l,k);
        ll ans=fr-fl;
        return ans;
    }
};
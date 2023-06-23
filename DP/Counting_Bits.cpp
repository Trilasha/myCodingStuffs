class Solution {
public:
    int count(int n)

        int cnt=0;
        while(n)
        {
            cnt+=n&1;
            n>>=1;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        //***using builtin function
        //vector<int> ans;
        // for(int i=0;i<=n;++i)
        // ans.push_back(__builtin_popcount(i));
        // return ans;


        //nlogn approach 
        // vector<int> ans;
        // for(int i=0;i<=n;++i)
        // ans.push_back(count(i));
        // return ans;


        //O(n)--> dp approach
        //after observing the pattern as 0112122312232334
        //dp[index]=dp[index-offset]+1;
        vector<int> dp(n+1);
        dp[0]=0;
        int offset=1;
        for(int i=1;i<=n;++i)
        {
            if(offset*2==i)
            offset*=2;
            dp[i]=dp[i-offset]+1;
        }

        return dp;
        
    }
};
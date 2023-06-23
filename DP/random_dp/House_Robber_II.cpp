class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n<=2)
        {
            return *max_element(nums.begin(),nums.end());
        }
        // 0 to n-2
        vector<int> dp(n);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        
        for(int x=2;x<n-1;++x)
        {
        dp[x]=max(dp[x-1],nums[x]+dp[x-2]); 
        }

        int mx=dp[n-2];

        // 1 to n-1
        dp.resize(n,0);
        dp[1]=nums[1];
        dp[2]=max(nums[1],nums[2]);
        
        for(int x=3;x<n;++x)
        {
        dp[x]=max(dp[x-1],nums[x]+dp[x-2]); 
        }

        mx=max(mx,dp[n-1]);

        return mx;
    }
};
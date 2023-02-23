//https://leetcode.com/problems/house-robber/solutions/1605133/c-discussing-all-solutions-dp-with-constant-space/?orderBy=most_votes

//tc->O(n)
//sc->O(n)
//for further optimization refer to the link given above


//bottomup
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        dp[0]=nums[0];
        if(n>1)
        dp[1]=max(nums[0],nums[1]);
        
        for(int x=2;x<n;++x)
        dp[x]=max(dp[x-1],nums[x]+dp[x-2]);

        return dp[n-1];
    }
};









//bottomup(tabulation) --> space optimized
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        int prev2=-1;
        int prev1=-1;
        prev2=nums[0];
        if(n>1)
        prev1=max(nums[0],nums[1]);
        
        for(int x=2;x<n;++x)
        {
            int curr=max(prev1,nums[x]+prev2);
            prev2=prev1;
            prev1=curr;
        }

        return max(prev1,prev2);
    }
};

//hehe
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);

        int prev2=0;
        int prev1=nums[0];
        
        for(int x=1;x<n;++x)
        {
            int curr=max(prev1,nums[x]+prev2);
            prev2=prev1;
            prev1=curr;
        }

        return prev1;
    }
};






//topdown 
class Solution {
public:
    int solve(int n,vector<int> &dp,vector<int> &nums)
    {
        if(n==0)
        return dp[n]=nums[0];

        if(n<0)return 0;

        if(dp[n]!=-1)
        return dp[n];

        int pick=nums[n]+solve(n-2,dp,nums);
        int not_pick=solve(n-1,dp,nums);

        return dp[n]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        n--;
        solve(n,dp,nums);
        return dp[n];

    }
};



//
class Solution {
public:
    //dp 
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> lis(n+1);

        for(int i=0;i<=n;++i)
        lis[i]=1;

        for(int i=1;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                if(nums[j]<nums[i] && lis[i]<(lis[j]+1))
                lis[i]=lis[j]+1;
            }
        }

        return *max_element(lis.begin(),lis.end());


    }
};






/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    //using lcs
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> sorted;

        set<int> st;
        for(auto &i:nums)
        st.insert(i);

        for(auto &i:st)
        sorted.push_back(i);

        //now find the lcs bw sorted and nums 

        vector<vector<int>> dp(n+1,vector<int>(sorted.size()+1));

        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=sorted.size();++j)
            {
                if(nums[i-1]==sorted[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[n][sorted.size()];

    }
};
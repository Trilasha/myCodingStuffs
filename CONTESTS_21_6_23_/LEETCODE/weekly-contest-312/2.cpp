class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int ans=0;
        int ct=0;
        vector<int> copy=nums;
        sort(copy.begin(),copy.end(),greater<int>());
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==copy[0])
            ct++;
            else if(nums[i]!=copy[0])
            {
                ans=max(ans,ct);
                ct=0;
            }
        }
        ans=max(ans,ct);
        return ans;
    }
};
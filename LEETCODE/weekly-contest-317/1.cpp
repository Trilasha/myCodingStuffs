
class Solution {
public:
    int averageValue(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]%2==0 && nums[i]%3==0)
            {
                ans.push_back(nums[i]);
            }
        }
        int sum=accumulate(ans.begin(),ans.end(),0);
        if(sum==0)
            return 0;
        else
        return sum/ans.size();
    }
};
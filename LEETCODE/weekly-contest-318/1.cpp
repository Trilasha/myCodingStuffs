
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int ct=0;
        for(int i=0;i<nums.size()-1;++i)
        {
            if(nums[i]==nums[i+1])
            {
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        
        vector<int> ans;
        for(auto &i:nums)
        {
            if(i!=0)
                ans.push_back(i);
            else if(i==0)
                ct++;
        }
        for(int i=0;i<ct;++i)
        {
            ans.push_back(0);
        }
        return ans;
    }
};

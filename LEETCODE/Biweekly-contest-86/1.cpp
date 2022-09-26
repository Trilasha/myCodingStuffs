class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        vector<int> v;
        set<int> s;
        int sum=0;
        for(int i=0;i<nums.size()-1;++i)
        {
            sum=nums[i]+nums[i+1];
            v.push_back(sum);
            s.insert(sum);
        }
        if(v.size()>s.size())
            return true;
        return false;
        
    }
};
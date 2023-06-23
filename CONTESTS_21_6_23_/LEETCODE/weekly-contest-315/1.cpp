class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int,int> mp;
        int ans=-1;
        for(auto &i:nums)
        {
            mp[i]++;
        }
        for(auto &i:nums)
        {
            if(i>0)
            {
                if(mp[-i]!=0 && i>ans)
                {
                    ans=i;
                }
                    
            }
        }
        return ans;
    }
};
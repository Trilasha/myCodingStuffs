class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();++i)
        {
            mp[nums[i]]++;
        }
        int max=-1;
        int occ=-1;
        
    for(auto &i: mp)
    {
        if(i.first%2==0 && i.second>occ)
        {
            max=i.first;
            occ=i.second;
        }
    }
    return max;
    }
};
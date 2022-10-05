class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
         if(nums1.size()%2==0 && nums2.size()%2==0)   
        {
             ans=0;
        }
        else if(nums1.size()%2!=0 && nums2.size()%2!=0)
        {
            for(int i=0;i<nums1.size();++i)
                ans^=nums1[i];
            for(int i=0;i<nums2.size();++i)
                ans^=nums2[i];
        }
        else if(nums1.size()%2==0 && nums2.size()%2!=0)
        {
             for(int i=0;i<nums1.size();++i)
                ans^=nums1[i];
            
        }
        else if(nums1.size()%2!=0 && nums2.size()%2==0)
        {
             for(int i=0;i<nums2.size();++i)
                ans^=nums2[i];
        }
        return ans;
    }
};
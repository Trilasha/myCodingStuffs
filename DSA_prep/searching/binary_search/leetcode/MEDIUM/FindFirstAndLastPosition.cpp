/*
34. Find First and Last Position of Element in Sorted Array
Medium

11236

303

Add to List

Share
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/
//************CODE1**************
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        int ans_l=-1;
        int ans_r=-1;
        int n=nums.size();
        //for the leftmost one
        int left=0;int right=n-1;
        long long mid;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(nums[mid]==target)
            {
                ans_l=mid;
                right=mid-1;
            }
            else if(nums[mid]>target)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
          
        }
         left=0, right=n-1;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(nums[mid]==target)
            {
                ans_r=mid;
                left=mid+1;
            }
            else if(nums[mid]>target)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
          
        }
        ans[0]=ans_l;
        ans[1]=ans_r;
       return ans;
    }
};


//******************CODE2(using lb and ub)******************

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       vector<int> ans(2);
        if(nums.size()==0)
        {
            // ans.push_back(-1);
            // ans.push_back(-1);
            //observe and analyse the mistakes when written like this
            ans[0]=-1;
            ans[1]=-1;
            return ans;
        }
        vector<int>:: iterator low,high;
          low=lower_bound(nums.begin(),nums.end(),target);
          high=upper_bound(nums.begin(),nums.end(),target);
        if(low==nums.end())
            ans[0]=-1;
        else if(nums[low-nums.begin()]!=target)
            ans[0]=-1;
        else
            ans[0]=low-nums.begin();
        if(high==nums.begin())
           ans[1]=-1;
        else if(nums[(high-nums.begin())-1]==target)
            ans[1]=(high-nums.begin())-1;
        else
            ans[1]=-1;
        return ans;
    }
};
/*
et's call an array arr a mountain if the following properties hold:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... arr[i-1] < arr[i]
arr[i] > arr[i+1] > ... > arr[arr.length - 1]
Given an integer array arr that is guaranteed to be a mountain, return any i such that arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

 

Example 1:

Input: arr = [0,1,0]
Output: 1
Example 2:

Input: arr = [0,2,1,0]
Output: 1
Example 3:

Input: arr = [0,10,5,2]
Output: 1
 

Constraints:

3 <= arr.length <= 104
0 <= arr[i] <= 106
arr is guaranteed to be a mountain array.
 
*/
//**************MY CODE******************
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        long long left=0;
        long long right=n-1;
        long long mid;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(mid==0)
                left=mid+1;
            else if(mid==n-1)
                right=mid-1;
            else if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
                return mid;
            else if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1])
                left=mid+1;
            else if(arr[mid]<arr[mid-1] && arr[mid]>arr[mid+1])
                right=mid-1;
        }
        return -1;
    }
};













//***************3 times faster code*******************
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans=0,start=0,end=arr.size()-1;
        while(start<end){
            int mid=(start+end)/2;
            if(arr[mid]>arr[mid+1]){
                end = mid;
                ans=mid;
            }
            else{
                ans=mid+1;
                start=mid+1;
            }
        }
        return ans;
    }
};
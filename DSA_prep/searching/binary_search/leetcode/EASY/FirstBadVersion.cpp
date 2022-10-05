/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

 

Example 1:

Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.
Example 2:

Input: n = 1, bad = 1
Output: 1
 

Constraints:

1 <= bad <= n <= 231 - 1
*/

//******************MY CODE*****************
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long lo=1,hi=n;
        long long mid;
        while(hi-lo>1)
        {
            mid=lo+(hi-lo)/2;
            if(isBadVersion(mid)==1)
                hi=mid;
           else if(isBadVersion(mid)==0)
               lo=mid+1;
        }
              if(isBadVersion(lo)==1)
              return lo;
              else
              return hi;
              //to find out the first true--> FFFFTTT-->monotonic

              //in this code,the left and right will always be the values present at two different adjacent indexes,so we have to check which one is true and which one is false before output
        
    }
};

//****modified versions****
//1
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
   int firstBadVersion(int n) {
        long long lo=1,hi=n;
        long long mid;
        while(hi-lo>=1)
        {
            mid=lo+(hi-lo)/2;
            if(isBadVersion(mid)==1)
                hi=mid;
           else if(isBadVersion(mid)==0)
               lo=mid+1;
        }
              // if(isBadVersion(lo)==1)
              return lo;
              // else
              // return hi;
        
    }
};
//2
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
   int firstBadVersion(int n) {
        long long lo=1,hi=n;
        long long mid;
        while(hi-lo>=1)
        {
            mid=lo+(hi-lo)/2;
            if(isBadVersion(mid)==1)
                hi=mid;
           else if(isBadVersion(mid)==0)
               lo=mid+1;
        }
              // if(isBadVersion(lo)==1)
              return lo;
              // else
              // return hi;
        
    }
};

////////1 and 2 almost same but written to show that now both return lo; and return hi; are correct.





//***********CODE AVAIABLE IN THE SOLUTION PAGE***************
public int firstBadVersion(int n) {
    int left = 1;
    int right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
    //return right also correct
    //in this code,the loop breaks as soon as right == left ,so we can output any of them either left or right both  are correct
}

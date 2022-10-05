/*
Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

 

Example 1:

Input: x = 4
Output: 2
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
 

Constraints:

0 <= x <= 231 - 1
*/

//****************MY CODE*********************
class Solution {
public:
    int mySqrt(int x) {
     if (ceil((double)sqrt(x)) == floor((double)sqrt(x)))
            return sqrt(x);
        double eps=1e-6;
        double num=(double)x;
        double left=1,right=num,mid;
        while(right-left>eps)
        {
            mid=(left+right)/2;
            if(mid*mid<num)
                left=mid;
            else
                right=mid;
        }
            return left;
    }
};
//faster than 100% hehehe

//**************ANOTHER 100% FASTER CODE***************
class Solution {
public:
	int mySqrt(int x) {
		unsigned long long s =0;
		unsigned long long l =x;

		if(x ==1 ){return 1;}
		while(s<=l)
		{
			//unsigned long long mid = (s+l)/2;
            unsigned long long mid = s+(l-s)/2;
            //both are correct
			if(mid*mid ==x)
			{
				return mid;
			}

			else if(mid*mid>x )
			{
				if((mid-1)*(mid-1)<x)
				{
					return mid-1;
				}
				else{
					l = mid -1;
				}
			}
			else
			{
				s =mid + 1;
			}
		}
			return -1;

	}
};
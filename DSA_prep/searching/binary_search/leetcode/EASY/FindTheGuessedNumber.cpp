/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API int guess(int num), which returns three possible results:

-1: Your guess is higher than the number I picked (i.e. num > pick).
1: Your guess is lower than the number I picked (i.e. num < pick).
0: your guess is equal to the number I picked (i.e. num == pick).
Return the number that I picked.

1 <= n <= 231 - 1
1 <= pick <= n

Input: n = 2, pick = 1
Output: 1
*/


///////////////////////////////////////////////////CODE/////////////////////////////////////


/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
//had runtime error when mid,left and right were int but why is thatso?
//**********************************1-->My code
class Solution{
public: 
    int guessNumber(int n) {
        long long left=1,right=n;
        long long mid;
        long long temp;
        while(right-left>1)
        {
           mid=(left+right)/2;
             temp=guess(mid);
            if((temp)>0)
                left=mid+1;
            else
                right=mid;
        }
        int temp2=guess(left);
        int temp3=guess(right);
        if(temp2==0)
            return left;
        else if (temp3==0)return right;
        else
            return -1;
    }


//**************************************2-->solution that was given
/* The guess API is defined in the parent class GuessGame.
   @param num, your guess
   @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
      int guess(int num); */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int low = 1;
        int high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int res = guess(mid);
            if (res == 0)
                return mid;
            else if (res < 0)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
}

//**************************************3-->claimed 0ms fastest code
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution{
public: 
   int guessNumber(int n) {
        long long int mid,left=1,right=n;
while(left<=right)
{
mid=left+(right-left)/2;
if(guess(mid)==0)
return mid;
else if(guess(mid)==1)
left=mid+1;
else
right=mid-1;
}
return -1;
}
        
    
};
//Exercise 11: Checking palindrome sequence
#include <stdio.h>


int isPalindrome(int num)
{
    //int t,rev=0;        //T Y P E = 1
    //t=num;
    //while (t!=0)
    //{
    //    rev=rev*10;
    //    rev=rev + t%10;
    //    t=t/10;
   // }
   // 
    //if (num==rev)
    //{
    //  return 1;
    //}
    //else
    //{
    //    return 0;
    //}




    int reversed = 0;     //T Y P E = 2(By Harry Bhai)
    int originalnumber= num;//This line is required because original value of num changes inside the loop
    //Method that helps to reverse a number
    while (num!=0)
    {
       reversed = reversed*10 +num%10;
       num = num/10;
    }
    printf("The reversed number is %d\n", reversed);
    
    if (originalnumber==reversed)
    {
        return 1;
    }
    else         //Even without else it will work...HOW???????
    {
        return 0;
    }
    

}

int main()
{
    int num;
    printf("Enter a number to check whether it is a palindrome or not\n");
    scanf("%d", &num);
    //My task is to complete this function 
if (isPalindrome(num))
{
    printf("This number is a palindrome\n");
}
else
{
    printf("This number is not a palindrome\n");
}


    return 0;
}
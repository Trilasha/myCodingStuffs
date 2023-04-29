//fib_recurisve(int n);
//if n==1 or n==2:
//return n

//else:
//return fib_recursive(n-1) + fib_recursive(n-2)


//n=42 using both recursive and iterative methods

//SOLUTION BY HARRY SIR


#include <stdio.h>

int fib_recursive(int n)
{
     if (n==1||n==2)
  {
     return n-1;

  }
  else
  {
     return fib_recursive(n-1) + fib_recursive(n-2);
  }
  
}

int fib_iterative(int n)
{                                             
    int a=0;                                          //o 1 1 2 3 5 8 13 21
    int b=1;

    for (int i = 0; i < n-1; i++)
    {
       b=a+b;   //these two operations will occur three times(for i=0,1,2) if n=4 and will return the final value of a as the result
       a=b-a;
    }
    
 return a;
  
}

int main()
{
    int number;
    printf("Enter the  index to get fibonacci series\n");
    scanf("%d", &number);
    printf("The value of fibonacci number at position number %d using iterative approach is %d\n", number, fib_iterative(number));
    printf("The value of fibonacci number at position number %d using recursive approach is %d\n", number, fib_recursive(number));
     
    return 0;
}
//NOTE:Recursive method takes more time to display the result than the iterative(loop)result
//In this case iterative approach is easier and better than the other one
//Solved done dy Harrybhai
#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number to check whether prime or not\n");
    scanf("%d", &n);
    int isPrime=1;
    for (int i = 2; i*i<n; i++)
    {
       if (n%i==0)
       {
          isPrime=0;
       }
       
    }
    if (isPrime)
    {
    printf("The number %d is prime", n);
    }
    else
    {
        printf("The number %d is not prime", n);
    }
    
    return 0;
}
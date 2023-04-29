#include <stdio.h>
int reverse(int a)
{
int rev=0;    
    int b=a;
    int rem;
    while (b!=0)
    {
        
      rem=b%10;
      rev=rev*10+rem;
      b=b/10;
    }
    return rev;
}
int main()
{
    int a;
    printf("Enter the number that you want the reverse of\n");
    scanf("%d", &a);
    printf("The reversed number generated is %d\n", reverse(a));;
    
    return 0;
}
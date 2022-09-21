//To find the binary equivalent of a decimal number
#include <stdio.h>
int main()
{
    int n;
    printf("Enter a decimal number\n");
    scanf("%d", &n);
    if (n==0)
    {
       printf("00000000");
    }
    int rem;
    int a[10];
    int i=0;
    while (n)
    {
        rem=n%2;
        n=n/2;
        a[i]=rem;
        i++;
    }
    for (int j = i-1; j >=0; j--)
    {
       printf("%d",a[j]);
    }
    
    
    
    

    return 0;
}
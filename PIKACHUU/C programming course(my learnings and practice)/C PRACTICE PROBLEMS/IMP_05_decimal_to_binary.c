//Harry bhai has also provided a separate video containing all the notes of C++>>>Check it out once
#include <stdio.h>
int main()
{
    //int n=10;//In n=0 is written then no result will be displayed becuse while(n) means while(n!=0) so loop will not run and hence no value of i
    //int rem;
    //int a[10];
    //int i=0;
    //while (n)
    //{
    //    rem=n%2;
    //    n=n/2;
    //    a[i]=rem;
    //    i++;
    //}
    //for (int j = i-1; j >=0; j--)
    //{
    //   printf("%d", a[j]);
    //}
    
    //Another code to even display the output when n=0
    int n;
    printf("Enter the number\n");
    scanf("%d", &n);
    int rem;
    int a[10];
    int i=0;
    if (n==0)
    {
       printf("0");
    }
    
    while (n)
    {
        rem=n%2;
        n=n/2;
        a[i]=rem;
        i++;
    }
    for (int j = i-1; j >=0; j--)
    {
       printf("%d", a[j]);
    }

    
    return 0;
}
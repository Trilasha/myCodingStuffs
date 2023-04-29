#include <stdio.h>
#include <math.h>
int main()
{
    int flag;
    int n;
    scanf("%d",&n);
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n%i==0)
        {
            printf("Not prime number!");
            flag=1;
            break;
        }
        
    }
    if (flag==0)
    {
        printf("Prime number!");
    }
    
    
    return 0;
}
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
int main()
{
    int n, k;
    scanf("%d", &n);
    bool flag = 0;
    for (int i = 2; k = sqrt(n); i < k; i++)
    {
        if (n % i == 0)
        {
            printf("Not Prime");
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("Prime");
    }

    return 0;
}
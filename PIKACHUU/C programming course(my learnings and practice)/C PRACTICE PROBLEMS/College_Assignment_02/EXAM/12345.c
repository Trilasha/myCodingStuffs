#include <stdio.h>
#include <math.h>

int main()
{
    int x, n;
    printf("Enter the numbers:\n");
    scanf("%d %d", &x, &n);
    float sum, i, s;
    sum = 1;
    i = 1;
    s = 1;
    for (int i = 1; i < n; i++)
    {
         int m=s*=i;
        //s *= i;
        sum += pow(x, i) / m;
    }
    printf("%f", sum);
    return 0;
}
#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    int arr[100];
    int i = 0;
    printf("Enter a decimal number:\n");
    scanf("%d", &n);
    if (n == 0)
    {
        printf("0");
    }

    while (n)
    {

        arr[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int k = 0; k <= i - 1; k++)
    {
        if (arr[k] == 0)
        {
            arr[k] = 1;
        }
        else if (arr[k] == 1)
        {
            arr[k] = 0;
        }
    }

    int pro = 0;

    for (int r = 0; r <= i - 1; r++)
    {
        pro += arr[r] * pow(2, r);
    }

    // printf("\n");
    printf("%d", pro);
    return 0;
}
//***Code for Q7***
#include <stdio.h>
int main()
{
    int n;
    printf("Enter a number(between 1 and 27):\n");
    scanf("%d", &n); // Enter the value of n betweeen 1 and 27
    int a, b, c, d;
    printf("All possible 3-digit combinations whose sum is equal to %d are listed below:\n", n);
    for (int i = 100; i <= 999; i++)
    {
        a = i % 10; // the digit at the one's place
        b = i / 10;
        c = b % 10; // the digit at the tenth place
        d = b / 10; // the digit at the hundrieth place

        if (n == a + c + d)
        {
            printf("%d ,", i);
        }
    }

    return 0;
}
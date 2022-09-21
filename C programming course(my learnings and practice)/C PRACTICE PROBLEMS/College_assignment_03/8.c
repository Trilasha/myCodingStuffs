//***Code for Q8***
#include <stdio.h>
int main()
{
    int num, sum = 0;
    printf("Enter a number:\n");
    scanf("%d", &num);
    printf("All the integers between 1 to 500 that are divisible by %d are: ", num);
    for (int i = 1; i <= 500; i++)
    {
        if (i % num == 0)
        {
            printf("%d ,", i);
            sum += i;
        }
    }
    printf("\n\n");
    printf("The sum of all such possible integers written above is : %d", sum);

    return 0;
}
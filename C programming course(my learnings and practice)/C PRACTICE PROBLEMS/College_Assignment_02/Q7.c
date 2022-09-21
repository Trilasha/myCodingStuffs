//***Code for Q7***
#include <stdio.h>
int main()
{
    int a, b, c;
    printf("Enter the 1st number:\n");
    scanf("%d", &a);
    printf("Enter the 2nd number:\n");
    scanf("%d", &b);
    printf("Enter the 3rd number:\n");
    scanf("%d", &c);
    if (a > b && a > c)
    {
        printf("The largest of the three entered numbers is %d\n", a);
    }
    else if (b > a && b > c)
    {
        printf("The largest of the three entered numbers is %d\n", b);
    }
    else
    {
        printf("The largest of the three entered numbers is %d\n", c);
    }
    return 0;
}
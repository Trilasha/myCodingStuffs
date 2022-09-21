#include <stdio.h>
int main()
{
    int x;
    scanf("%d", &x);
    switch (x)
    {
    case 1:
    case 2:
    case 3:
        printf("Joint family club");
        break;
    case 4:
    printf("Welcome");
    break;
    default:
    printf("Make your own");
        break;
    }

    return 0;
}
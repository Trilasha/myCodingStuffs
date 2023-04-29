#include <stdio.h>

int main()
{
    int num, index = 0;
    printf("Enter a number\n");
    scanf("%d", &num);

    do
    {
        printf("%d\n", index); //if we want to start it from 1 then write index +1
        index = index + 1;
    } while (index < num);

    return 0;
}

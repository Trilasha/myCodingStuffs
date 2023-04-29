//***Code for Q6***
#include <stdio.h>
int func(int *ptr)
{
    int original_num = *ptr;
    int i = 0, arr[100];
    while (*ptr >= 16)
    {
        arr[i] = *ptr % 16;
        *ptr /= 16;
        i++;
    }
    arr[i] = *ptr;
    printf("The corresponding value of %d in haxadecimal system is : ", original_num);

    for (int j = i; j >= 0; j--)
    {
        if (arr[j] == 10)
        {
            printf("A");
        }
        else if (arr[j] == 11)
        {
            printf("B");
        }
        else if (arr[j] == 12)
        {
            printf("C");
        }
        else if (arr[j] == 13)
        {
            printf("D");
        }
        else if (arr[j] == 14)
        {
            printf("E");
        }
        else if (arr[j] == 15)
        {
            printf("F");
        }
        else
            printf("%d", arr[j]);
    }
}
int main()
{
    int num;
    printf("Enter a decimal number :\n");
    scanf("%d", &num);
    func(&num);
    return 0;
}
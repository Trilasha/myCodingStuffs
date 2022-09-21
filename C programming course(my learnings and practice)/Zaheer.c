#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    printf("Enter the code\n");
    scanf("%s", str);
    if (strlen(str) == 8)
    {
        if ((str[0] + str[1]) % 2 == 0 && (str[1] + str[2]) % 2 == 0 && (str[2] + str[3]) % 2 == 0 && (str[3] + str[4]) % 2 == 0 && (str[4] + str[5]) % 2 == 0 && (str[5] + str[6]) % 2 == 0 && (str[6] + str[7]) % 2 == 0)
        {
            printf("Valid code");
        }

        else
        {
            printf("Invalid Code");
        }
    }
    else
    {
        printf("Invalid code");
    }

    return 0;
}
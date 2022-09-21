//Solution to Ex-8 Ctut48...by Harry sir
#include <stdio.h>
#include <stdlib.h> //for dynamic memory allocation

int main()
{
    int chars, i = 0;
    char *ptr;
    while (i < 3)
    {
        i = i + 1;
        printf("Emplyee %d:Enter the number of characters in your Employee Id\n", i+1);
        scanf("%d", &chars);
        ptr = (char *)malloc((chars + 1) * sizeof(char));
        printf("Enter your Employee Id\n");
        scanf("%s", ptr);
        printf("Your Employee Id is %s\n", ptr);
        free(ptr);
                
    }

    return 0;
}
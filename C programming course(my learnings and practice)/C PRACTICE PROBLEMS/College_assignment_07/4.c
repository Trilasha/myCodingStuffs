//***Code for Q4***
#include <stdio.h>
#include <string.h>
int main()
{
    
    char str[30];
    printf("Enter a string:\n");
    gets(str);
    printf("The entered string is:\n");
    puts(str);
    printf("All the duplicates in the above entered string are as follows:\n");
    int count = 1;
    int n = strlen(str);
    for (int i = 0; i < n; ++i)
    {
        count = 1;
        for (int j = i + 1; j < n; ++j)
        {
            if (str[i] == str[j])
            {
                count++;
                str[j] = '\0';
            }
        }
        if (count > 1)
        {
            printf("%c\n", str[i]);
        }
    }
    return 0;
}

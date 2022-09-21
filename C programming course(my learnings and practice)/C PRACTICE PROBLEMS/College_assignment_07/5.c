//***Code for Q5***//Modified
#include <stdio.h>
#include <string.h>
int main()
{
    char str1[100], str2[100];
    printf("Enter the first string(str1):\n");
    gets(str1);
    printf("Enter the second string(str2):\n");
    gets(str2);
    printf("The first string (str1) is : %s\n", str1);
    printf("The second string (str2) is : %s\n", str2);
    int n = strlen(str1);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < strlen(str2); ++j)
        {
            if (str1[i] == str2[j])
            {
                str1[i] = '\0';
            }
        }
    }
    printf("After removing all the characters from str1 that are also present in str2,\nstr1 now becomes: ");
    for (int i = 0; i < n; ++i)
    {
       // if (str1[i] != '\0') -->If this line i not written,then then the required characters will only get removed and the rest of the string remains the same
       //-->On giving this,all the spaces are removed and the characters come close to each other
            printf("%c", str1[i]);
    }
    return 0;
}
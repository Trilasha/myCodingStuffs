#include <stdio.h>
int countKro(char *x)
{
    int l = 0;
    while (*x != '\0')
    {
        *x++;
        l++;
    }
    return l;
}
void copyKrDoPlz(char *str1, char *str2)
{
    while (*str2 != '\0')
    {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
}
void reverseKrDoPlz(char *, char *);

int main()
{
    char a[100], b[100];
    printf("Enter The 1st String : ");

    gets(a);
    printf("The String Before Reverse is : %s", a);
    reverseKrDoPlz(a,b);
   //copyKrDoPlz(a, b);

    printf("The String After Reverse is : %s", a);
    return 0;
}
void reverseKrDoPlz(char *a, char *b)
{
//void copyKrDoPlz(char *str1, char *str2);
    int x = countKro(a);
    while (x--)
    {
        *b = *(a + x);
        *b++;
    }
    *b = '\0';
   copyKrDoPlz(a, b);
}
//***Code for Q6***//code directly copy pasted from gfg
#include <stdio.h>
#include <string.h>
void rev_string(char* b, char* e)
{
    char var;
    while (b < e) {
        var = *b;
        *b++ = *e;
        *e-- = var;
    }
}
void reverse_word(char* str)
{
    char* w_begin = str;
    char* var = str;
    while (*var) {
        var++;
        if (*var == '\0') {
            rev_string(w_begin, var - 1);
        }
        else if (*var == ' ') {
            rev_string(w_begin, var - 1);
            w_begin = var + 1;
        }
    }
 
   //rev_string(str, var - 1);
   strrev(str);
}
int main()
{
    char str[40];
    printf("Enter a string:\n");
    gets(str);
    printf("The entered string is :\n");
    puts(str);
    char* var = str;
    reverse_word(str);
    printf("The new string thus obtained by reversing the words of the previously entered string:\n");
    printf("%s",str);
    return 0;
}
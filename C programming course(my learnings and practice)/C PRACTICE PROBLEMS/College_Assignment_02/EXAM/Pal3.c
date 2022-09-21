#include <stdio.h>
char lower_to_upper(char c1)
{
    char c2;
    c2=(c1>='a' && c1<='z')?('A'+c1 - 'a'):c1;
    return c2;//braces can be given
}
void main()
{
    char lower,upper;
    printf("Please enter a lowercase character:");
    scanf("%c",&lower);
    upper = lower_to_upper(lower);
    printf("\nuppercase equivalent is %c\n", upper);

}
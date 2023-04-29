#include <stdio.h>
void func()
{
    char c;
    scanf("%c",&c);
    if(c!='\n'){
        func();
        printf("%c",c);
    }
}
int main()
{
    printf("Give your input:");
    func();
    return 0;
}
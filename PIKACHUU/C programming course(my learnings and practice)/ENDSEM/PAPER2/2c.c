#include <stdio.h>
struct try
{
    int n[5];
    union {
        float x;
        char ch[10];
    }u;
}s;
int main()
{
    printf("%d",sizeof(struct try));
    return 0;
}
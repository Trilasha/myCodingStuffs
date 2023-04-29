#include <stdio.h>
int main()
{
    float x,y,z;
    printf("Enter x and y :");
    scanf("%f %f",&x,&y);
    z=x>y?(x/3):(y/2);
    printf("z=%.2f",z);
    return 0;
}
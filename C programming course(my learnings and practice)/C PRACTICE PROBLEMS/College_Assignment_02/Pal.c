#include <stdio.h>
int main()
{
    float x,y;
    do
    {
        scanf("%f", &x);
        if (x<0)
        {
        printf("ERROR:entered negative value");
        continue;
        }
       // x=x+y;
        //y=y+10;
        printf("Good evening everyone");
    } while (x<=100);
    


    return 0;
}
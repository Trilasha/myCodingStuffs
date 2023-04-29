#include <stdio.h>
int num; //without this line error will get displayed
 main()//Warning will appear which can be resolved by writing atleast void
{
    extern int num;
    num=20;
    printf("%d",sizeof(num));
    
}
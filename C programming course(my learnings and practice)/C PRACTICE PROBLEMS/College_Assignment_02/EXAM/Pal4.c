#include <stdio.h>
int max_of_two(int x,int y)
{
    int max;
    max=(x>y)?x:y;
    return max;
}
 void main() //or int main and return 0 can also be written
{
    int x,y;
    printf("Enter the values of x and y:");
    scanf("%d %d",&x,&y);
    printf("The maximum of the two entered numbers is : %d", max_of_two(x,y));
    
}
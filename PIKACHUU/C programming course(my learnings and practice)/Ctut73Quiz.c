//When user is required to input the two values
#include <stdio.h>
int avg(int x,int y)
{
  
    return (x+y)/2;
}
greetGaAndExecute(int (*fptr)(int,int),int x,int y)
{
    int x,y;
printf("Good Afternoon user\n");
  printf("Enter the two numbers of which you want to find the average:-\n");
scanf("%d\n%d", &x,&y);

printf("The average of the two entered numbers is %d\n", fptr(x,y));

}
greetGeAndExecute(int (*fptr)(int,int))
{
int x,y;
printf("Good Afternoon user\n");
  printf("Enter the two numbers of which you want to find the average:-\n");
scanf("%d\n%d", x,y);

printf("The average of the two entered numbers is %d\n", fptr(x,y));
}



int main()
{
    int (*ptr)(int,int);
    ptr=&avg;
greetGaAndExecute(ptr);
    
    return 0;
}
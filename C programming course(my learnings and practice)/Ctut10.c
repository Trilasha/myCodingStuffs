#include <stdio.h>

// Learning the usage of all the types of If statements

int main()
{
    int age;
     printf("Enter your age\n") ;
     scanf("%d", &age);
     printf("You have entered %d as your age\n", age);
if (age>=18)
{
  printf("You can vote!");
}
//till this part only if statement type 1

else if (age>10)
{
   printf("You are between 10 to 18 and so you can vote for kids");
}
else
{
    printf("Sorry you are too young to vote!");
}


//Skipping the else if part will give you type2 and all three considered together will give you type3





    return 0;
}

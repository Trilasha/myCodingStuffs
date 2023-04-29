//***Code for Q9***/////WHAT IS THE PROBLEM WITH THIS CODE??
#include <stdio.h>
#include <stdlib.h>
typedef struct employee
{
   int id;
   char name[40];
   int age;
} ep;
int main()
{
    int i=1;
struct ep *emp_1_ptr,emp_1,emp_2;
 emp_1_ptr=&emp_1;
printf("Employee No. %d--> Enter your id:\n",i);
scanf("%d",&emp_1_ptr->id);
printf("Enter your name:\n");
scanf("%s",&emp_1_ptr->name);
printf("Enter your age:\n");
scanf("%d",&emp_1_ptr->age);
printf("DISPLAYING the entries for EMPLOYEE NO. %d:\n",i++);
printf("ID -->%d\n",emp_1_ptr->id);
printf("NAME-->%s\n",emp_1_ptr->name);
printf("AGE-->%d\n",emp_1_ptr->age);
    return 0;
}
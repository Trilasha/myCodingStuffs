#include <stdio.h>
#include <stdlib.h>


int main()
{
    /*
Dynamic Memory All1ocation 
ABC Pvt Ltd. manages employee records of other companies.
Employee Id can be of any length and it can contain any character
for 3 employees you have to take the 'length of employee id' as the input in a length integer variable
then you have to take employee id as the input and display it on the screen
Store the employee id in a character array which is allocated dynamica1ly
you have to create only one character array dynamically
*/

//CONSIDERING THE EID TO BE COMPOSED OF ONLY INTEGERS(Exercise8)


    int *ptr;
    int n;
    printf("Employee 1:Enter the number of integers in your eid:\n");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));
    printf("Enter your eid:\n");
    scanf("%d", &(*ptr));
    printf("The eid of Employee no. 1 is %d\n", *ptr);

    free(ptr);

    printf("Employee 2:Enter the number of integers in your eid:\n");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));
    printf("Enter your eid:\n");
    scanf("%d", &(*ptr));
    printf("The eid of Employee no. 2 is %d\n", *ptr);

    printf("Employee 3:Enter the number of integers in your eid:\n");
    scanf("%d", &n);
    ptr = (int *)realloc(ptr, n * sizeof(int));
    printf("Enter your eid:\n");
    scanf("%d", &(*ptr));
    printf("The eid of Employee no. 3 is %d\n", *ptr);

    free(ptr);

    return 0;
}
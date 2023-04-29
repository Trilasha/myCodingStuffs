#include <stdio.h>
#include <stdlib.h>


int main()
{
char *ptr;
    int n;
    printf("Employee 1:Enter the number of characters in your eid:\n");
    scanf("%d", &n);
    ptr = (char *)malloc((n+1) * sizeof(char));
    printf("Enter your eid:\n");
    scanf("%s", ptr);
    printf("The eid of Employee no. 1 is %s\n", ptr);  //Why *ptr not written?

    free(ptr);

    printf("Employee 2:Enter the number of characters in your eid:\n");
    scanf("%d", &n);
    ptr = (char *)malloc((n+1) * sizeof(char));
    printf("Enter your eid:\n");
    scanf("%s",ptr);
    printf("The eid of Employee no. 2 is %s\n", ptr);

    printf("Employee 3:Enter the number of characters in your eid:\n");
    scanf("%d", &n);
    ptr = (char *)realloc(ptr, (n+1) * sizeof(char));
    printf("Enter your eid:\n");
    scanf("%s", ptr);
    printf("The eid of Employee no. 3 is %s\n", ptr);

    free(ptr);

    return 0;
}
//Solution by Harry Sir is given in Ctut50.c

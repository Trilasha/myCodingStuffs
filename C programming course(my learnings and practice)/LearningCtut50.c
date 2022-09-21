//Importance of getchar()



#include <stdio.h>
#include <stdlib.h> //for dynamic memory allocation

int main()
{
    int chars, i = 0;
    char a,b;
    char *ptr;
    while (i < 3)
    {
        printf("Emplyee %d:Enter the number of characters in your Employee Id\n", i+1);
        scanf("%d", &chars);

        getchar();                              //Solution 1: If we don't write this then on pressing the enter key
        printf("Enter the value of a\n");       //we will enter into input buffering and the enter key will be considered
        scanf("%c", &a);                        //as a valid input for %c so it will be accepted by the succeeding scanf

        getchar();                              //Solution 2: Even without using getchar() we can solve this problem 
        printf("Enter the value of b\n");       //by giving a space before %c 
        scanf("%c", &b);                        //like scanf(" %c", &a);



        ptr = (char *)malloc((chars + 1) * sizeof(char));
        printf("Enter your Employee Id\n");
        scanf("%s", ptr);
        printf("Your Employee Id is %s\n", ptr);
        free(ptr);
                i = i + 1;
    }

    return 0;
}
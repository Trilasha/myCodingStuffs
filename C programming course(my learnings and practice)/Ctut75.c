#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    int a;
    int *i2;
    while (i < 45545)
    {
        printf("Welcome to CodeWithharry\n");
        i2 = malloc(34444 * sizeof(int));
        if (i % 100 == 0)
        {
            getchar();
        }

        i++;
        free(i2);//WIthout this statement it would be a memory leak situation
    }

    return 0;
}
//When the program is run for the first time,i=0 so i is a multiple of 100 and i%100==0
//hence the if condition is satisfied so the loop runs only once
//Displaying the printf and the first enter key is taken by getchar()
//and the program ends temporarily
//But pressing enter key again will display the printf statement 101 times to reach the initial condition
//when i=100 and i%100==0 condition will be fulfilled

//Before writing free(i2),run the code 3-4 times and after evry run
//right-click on thr task bar and click on task manager and check the memory occupancy of a.exe file
//we will observe that with every run,the memory consumption go on increasing
//But if free(i2) is written then we will observe that with every run the memory occupancy does not change and remains constant

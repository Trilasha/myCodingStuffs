#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int generateRandomNumber(int n)
{
    srand(time(NULL));     //time NULL returns time in seconds   //if written srand(45)then only one value will appear
    return rand()%n;
}


int main()
{
    printf("The random number between 0 and 100 is %d\n", generateRandomNumber(5)); //srand takes seed as an input and is defined inside stdlib.h

/*Also can be written in the following way;
int main()
{
    srand(time(NULL));
    printf("The random number between 0 to 100 is %d\n", rand()%100);  //Considering n=100
}
*/


    return 0;
}
#include <stdio.h>
int main() //write main2 for Ctut59.c
{
    int a = 34;
    int *ptr = NULL;                              //if we keep the pointer uninitialized like int *ptr;then there is no guarantee of what it will return
    if (ptr != NULL)                              //For single condition {} can be skipped in if statement but better to use
        printf("The address of a is %d\n", *ptr); //if only lineno.7 is written without lineno.6 then program will get confused or rather crash
    else                                          //But without lineno.6 if we write only ptr in lineno.7 then it will return the value of the address of NULL pointer as 0
    {
        printf("The pointer is a null pointer and cannot be dereferenced\n");
    }

    return 0;
}
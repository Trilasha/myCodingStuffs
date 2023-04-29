#include <stdio.h>
typedef struct Student
{
    int id;
    int marks;
    char fav_char;
    char name[34];
} std;

int main()
{
    std s1, s2; //so now both struct Student and std will work
    s1.id = 34;
    s2.id = 54;
    printf("The value of s1's id is %d\n", s1.id);
    printf("the value of s2's id is %d\n", s2.id);

    // int* a, b;                           //here it treats a as a pointer and b as an integer like int *a,b;
    typedef int *intPointer;                //Showing the use of typedef in this case and if we use intPointer then both a and b are treated as pointers now
    intPointer a, b;
    int c = 89;
    a = &c;
    b = &c;
    return 0;
}
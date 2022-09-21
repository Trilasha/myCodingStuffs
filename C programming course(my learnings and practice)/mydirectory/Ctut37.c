#include <stdio.h>
#include <string.h> 

struct Student 
{
    int id;
    int marks;
    int fav_char;
    char name[34];    //For adding this member we have to add another C library i.e,#include <string.h>

};

int main()
{
    struct Student harry,ravi,shubham;   //here this is a local variable
    harry.id=1;
    ravi.id=2;
    shubham.id=3;
    harry.marks=268;
    ravi.marks=268;
    shubham.marks=268;
    harry.fav_char='t';
    ravi.fav_char='t';
   shubham.fav_char='t';
   strcpy(harry.name,"harry Potter student of the year");
   printf("Harry got %d marks\n", harry.marks);
   printf("Harry's name is %s\n", harry.name);
    return 0;
}

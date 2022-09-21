//To understand the difference between local and global variables(compare with Ctut37.c)



#include <stdio.h>
#include <string.h> 

struct Student 
{
    int id;
    int marks;
    int fav_char;
    char name[34];    //For adding this member we have to add another C library i.e,#include <string.h>

} harry,ravi,shubham;
                                              //Either can be written as in lineno.15 or lineno.17
//struct Student harry,ravi,shubham;  
void  print()
{
    printf("%s", harry.name);
}

int main()
{
 
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



   print();    //Upon calling print function we get the output because harry is a global variable now
               //If the same thing would have been done keeping it as local variable then error wil be displayed

    return 0;
}

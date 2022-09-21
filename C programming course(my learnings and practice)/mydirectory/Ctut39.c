#include <stdio.h>
#include <string.h>

union student 
{
    int id;
    int marks;
    char fav_char;
    char name[34];
};

int main()
{
    union student s1;
    s1.id=1;
    s1.marks=45;
    s1.fav_char='u';
    strcpy(s1.name, "Harry");          //The last will give authentic value and others will get corrupted
                                       //After alloting to the greatest one that requires maximum share,it shares the remaining among others
    printf("The id is %d\n", s1.id);   //So only one will be used or active and others will show garbage values
    printf("The marks is %d\n", s1.marks );
    printf("The fav_char is %c\n", s1.fav_char);     //Since character so %c
    printf("The name is %s\n", s1.name);             //Since string so %s


    return 0;
}
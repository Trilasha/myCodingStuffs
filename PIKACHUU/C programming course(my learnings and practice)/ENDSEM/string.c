#include <stdio.h>
int main()
{
    char line[81],character;
int c;
c=0;
printf("Enter test.Press<Return>> at end\n");    
do
{
   character=getchar();
   line[c]=character;
   c++;
} while(character!='\n');{
   // c=c-1;
    //line[c]='\0';
    printf("\n%s\n",line);

}

    return 0;
}
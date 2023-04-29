#include <stdio.h>
int main()
{
    FILE *ptr = NULL;
    ptr = fopen("myfile.txt", "r");
   // ptr = fopen("myfile.txt", "w");

    //FGETC FUNCTION UTILITY
    char c= fgetc(ptr);
    printf("The character I read was %c\n", c);
    c=fgetc(ptr);         //If initialized once again
    printf("The character I read was %c\n", c);
    fclose(ptr);          //This is our responsibilty to close the file

    //FGETS FUNCTION UTILITY
     char str[34];
     fgets(str,6,ptr);
     printf("The string is %s\n", str);

   //fputc('o', ptr);     //for fputc and fputs one has to follow lineo.6(write mode on;a also can be written;close 9to13 and 16to18)
   //fputs("this is harry", ptr);





   //***write some content in myfile.txt and replace "w" with "r+","w+" and "a+" one by one in lineno.6 keeping linenos.20 and 21 intact and commenting out others now observe the change
   //***Now comment out lineno.s 20 and 21 to observe the changes in the reading mode(linenos.16 to 18 and lineno.6 will have r+,w+,a+ though not used for reading purpose)
    return 0;
}
#include <stdio.h>
int main()
{
    FILE *ptr = NULL;
    char string[64]="THIS CONTENT IS WRITTEN TO SHOW THE SECOND TYPE";//this string is declared for 2(otherwise mytext.txt originally had 3lines of text )

    //***1.READING A FILE***
    //ptr = fopen("myfile.txt", "r");
    //fscanf(ptr, "%s", string);   //So it actually brought the entire content of the file in a single string(but ends as soon as it encounters a space)
    //printf("The content of this file has %s\n", string);

    //***2.WRITING A FILE***
    ptr = fopen("myfile.txt", "w");//On running the code,the content in myfile.txt gets replaced with the new one
    fprintf(ptr,"%s", string);     //If instead of "w", we open the file in append mode("a")then observe the change
                                   //In appen mode,the new contents go on adding with the older ones whenever run 

    return 0;
}
#include <stdio.h>
int main(int argc, char const *argv[])
{
    printf("The value of argc is %d\n", argc);  //If in the terminal, .\Ctut68.exe harry is -->is written the value will come as 3.
    for (int i = 0; i < argc; i++)
    {
        printf("This argument number %d has value of %s\n", i, argv[i]); //By default the argument at index number 0 will be the full path with the file name

    }
                                                                          //All the arguments that we will give will be taken as strings 
    return 0;
}

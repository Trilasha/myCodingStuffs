/*
Input:
<h1>This is a heading</h1>
Output:
this is a heading

Input:
<span>This is a heading2</span>
Output:
This is a heading2
*/

#include <stdio.h>
#include <string.h>
void parser(char *string)
{
    int in = 0; //variable to track whether we are inside the tag
    int index = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == '<')
        {
            in = 1;
            continue;
        }
        else if (string[i] == '>')
        {
            in = 0;
            continue;
        }
        if (in == 0)   //we are no longer inside the tag
        {
            string[index] = string[i];     //index will be <= i
            index++;
        }
    }
    string[index] = '\0';
    //Remove the trailing spaces from the beginning
    while (string[0] == ' ')
    {
        //shift the string to the left
        for (int i = 0; i < strlen(string); i++)
        {
            string[i] = string[i + 1];
        }
    }
    //Remove the trailing spaces from the end
    while (string[strlen(string) - 1] == ' ')
    {
        string[strlen(string) - 1] = '\0';
    }
}

int main()
{
    char string[] = "<h1>     This is a heading     </h1>";
    parser(string);
    printf("The parsed string is ~~%s~~", string);
    return 0;
}

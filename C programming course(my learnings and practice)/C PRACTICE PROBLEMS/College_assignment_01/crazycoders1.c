//Done by me
#include <stdio.h>
int main()
{
    char ch;
    int t=1;;
    //label:
    while(t)
    {
    printf("Enter a character from the vibgyor:\n");
    scanf("%c", &ch);
    switch (ch)
    {
    case 'v':
        printf("Colour is Violet.");
        t=0;
        break;
         case 'i':
        printf("Colour is Indigo.");
         t=0;
         break;
         case 'b':
        printf("Colour is Blue.");
         t=0;
        break;
         case 'g':
        printf("Colour is Green.");
         t=0;
        break;
         case 'y':
        printf("Colour is Yellow.");
         t=0;
        break;
         case 'o':
        printf("Colour is Orange.");
         t=0;
        break;
         case 'r':
        printf("Colour is Red.");
         t=0;
        break;
        
    
    default:
    printf("Invalid character entered.\n");
    //getchar();
    //goto label;
        break;
    }
    }
    return 0;
}
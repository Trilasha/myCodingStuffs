//Exercise no. 3
//Solution by Harry given in Ctut24.c

#include <stdio.h>
int main()
{
    
   
    int a, g;
    float b, c, d, e, f;
    
    printf("Welcome to our platform\n\v");
    printf("Select the type of conversion that you are looking fo:\n Press \t 1)km to miles\n 2)inch to foot\n 3)cm to inch\n 4)pound to kg\n 5)inch to metre\n");
    scanf("%d", &a);


    printf("So you have selected option %d\n\t", a);
    switch (a)
    {
    case 1:
       printf("Enter the value in km\n");
       scanf("%f", &b);
       printf("The corresponding value in miles is %f\n", b*0.621);
       
       printf("Do want to continue?\n\t Press 1 to continue and 0 to discontinue\n");
        scanf("%d", &g);
        if (g==0)
        {
            goto end;
        }
        
        
        

         case 2:
       printf("Enter the value in inch\n");
       scanf("%f", &c);
       printf("The corresponding value in foot is %f\n",c*0.0833);
        break;
         case 3:
       printf("Enter the value in cm\n");
       scanf("%f", &d);
       printf("The corresponding value in inch is %f\n", d*0.394);
        break;
         case 4:
       printf("Enter the value in pound\n");
       scanf("%f", &e);
       printf("The corresponding value in kg is %f\n",e*0.454);
        break;
         case 5:
       printf("Enter the value in inch\n");
       scanf("%f", &f);
       printf("The corresponding value in metre is %f\n", f*0.0254);
        break;

    end:
   

    return 0;
 }
 

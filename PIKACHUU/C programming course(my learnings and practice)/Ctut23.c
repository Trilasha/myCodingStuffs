#include <stdio.h>


//Total 3types have been shown



int main()
{
    int marks[4];

    for (int i = 0; i < 4; i++)                                                   //this is an example of 1-D array
    {
        printf("Enter the value of %d element of the array\n", i);     //If we delete codes fron line number 
        scanf("%d", &marks[i]);                                    //12 to 16 then write int marks[4]={4,5,6,7},            
    }                                                              //and keep the code from lineno. 20 to 24
    
                                                          //if done in 1 line then called as declaration and initialisation
                                                          //even if we don't write 4 then also ok but don't do in 2-D
    for (int i = 0; i < 4; i++)
    {
        printf("The value of %d element of the array is %d\n", i, marks[i]);
        
    }




    /*marks[0] = 34;                                       //simple code after int marks part to understand arrays
    printf("Marks of student 1 is %d\n", marks[0]);
    marks[0] = 4;
    marks[1] = 34;
    marks[2] = 54;
    marks[3] = 64;
    printf("Marks of student 1 is %d\n", marks[0]);
    return 0;
    */



}

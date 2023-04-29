#include <stdio.h>

int main()
{
    int i, j;
    for ( i = 0,j=0; j<3,i < 5; i++)                   //Exp1 can be skipped but you have to mention the initial value in the int part so no specific advantage of being optional
    {                                                  //i.e,int i=0,j=0;
                                                       //for(;i<5;i++) .....


       printf("%d \t %d\n", j,i);                  //if i,j written then the columns will get interchanged
       
    }
    
    return 0;
}                                                            //Code to explain the properties of Exp2
                                                             //int i, j;
                                                             //for ( i = 0,j=0; i < 5,j<3; i++){     //if Exp2 is interchanges still it will show 1 to 4 since it wil follow only the last condition and others wil become statements to be printed
                                                             //  printf("%d \t %d\n", j,i);           //statement concept can be understood by putting j=ny number say 3
                                                             //j++;}
 


                                                              /* Code to explain the properties of Exp33 
                                                                      int i, j;
                                                                    for ( i = 0,j=0; i < 5; i++, j++){}
                                                                    printf("%d \t %d\n", j,i);} 

                                                                    also to show the optional nature of
                                                                   Exp3 we can write i++;j++; after printf line and before }*/ 
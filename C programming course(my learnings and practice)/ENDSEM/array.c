#include <stdio.h>
int main()
{
    //int tab[3][5]={{0},{0},{0}};
    //int tab[3][5]={{0},{0}};
    //int tab[3][5]={{1,1},{2}};
    int tab[3][5]={{0,0,0},{1,1,1}};
    //int tab[][5]={{1,1},{2}}; //last row garbage value
    //int tab[][3]={{0,0,0},{1,1,1}}; -->in the loops n should also change


    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d",tab[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

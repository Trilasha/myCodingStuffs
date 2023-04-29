#include <stdio.h>
int main()
{
    union id{
        char colour;
        int size;
    };
    struct clothes{
        char manufacture[20];
        float cost;
        union id description;
    }shirt,blouse;
printf("%d\n",sizeof(union id));
shirt.description.colour='w';
printf("%c %d\n",shirt.description.colour,shirt.description.size);
shirt.description.size=12;
printf("%c %d\n",shirt.description.colour,shirt.description.size);

    
    return 0;
}
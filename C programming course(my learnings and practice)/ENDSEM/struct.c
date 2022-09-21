#include <stdio.h>
int main()
{
    struct id{
        char colour;
        int size;
    };
    //typedef struct clothes{
    //    char manufacture[20];
    //    float cost;
    //    struct id description;
    //} cloth;
     struct clothes{
        char manufacture[20];
        float cost;
        struct id description;
    };
   // }shirt,blouse;   -->3 ways
   struct clothes shirt,blouse;
   //cloth shirt,blouse;
printf("%d\n",sizeof(struct id));
shirt.description.colour='w';
printf("%c %d\n",shirt.description.colour,shirt.description.size);
shirt.description.size=12;
printf("%c %d\n",shirt.description.colour,shirt.description.size);
    return 0;
}
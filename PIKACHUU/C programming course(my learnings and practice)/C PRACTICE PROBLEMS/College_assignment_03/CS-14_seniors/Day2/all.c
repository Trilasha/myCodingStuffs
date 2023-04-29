#include <stdio.h>

// int *ptr;
// int x;
// ptr=&x;
//*ptr=0;
// printf("x=%d\n",x);
// printf("*ptr=%d\n",*ptr);
//*ptr+=5;
//  printf("x=%d\n",x);
// printf("*ptr=%d\n",*ptr);
//(*ptr)++;
//  printf("x=%d\n",x);
// printf("*ptr=%d\n",*ptr);

//***3(LEARNING)
/// float arr[5]={12.5,10.0,13.5,90.5,0.5};
/// float *ptr1=&arr[0];
/// float *ptr2=ptr1+3;
/// printf("%f",*ptr2);
/// printf("%d",ptr2-ptr1);

// 4     //CONFUSION
//   struct st
//{
// int x;
// static int y;
//};
// int main()
//{
//    printf("%d", sizeof(struct));
//    return 0;
//}

// 5
// int main()
//{
//    struct site
//    {
//        char name[] = "GeeksQuiz";
//        int no_of_pages = 200;
//    };
//    struct site *ptr;
//    printf("%d", ptr->no_of_pages);
//    printf("%s", ptr->name);
//    getchar();
//    return 0;
//}

// 6
// void func(int x)
//{
//     x=30;
// }
// int main()
//{
// int y=20;
// func(y);
// printf("%d",y);
//     return 0;
// }

// 7
// int main()
//{
//     char *ptr="GeeksQuiz";
//     printf("%c\n",*&*&*ptr);
//     return 0;
// }

// 8   //CONFUSION
int f(int x, int *py, int **ppz)
{
    int y, z;
    **ppz += 1;
    z = **ppz;
    *py += 2;
    y = *py;
    x += 3;
    return x + y + z;
}
void main()
{
    int c, *b, **a;
    c = 4;
    b = &c;
    a = &b;
    printf("%d", f(c, b, a));
    return 0;
}

// Zaheer code rectify+group one code+how elements can be inserted in an array  using recursion and some others
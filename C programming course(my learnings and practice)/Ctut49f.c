// Quiz covering the storage classes by GFG
#include <stdio.h>
 int main()
{
//  1)
//  static int i=5;
//  if(--i){
//	main();
//	printf("%d ",i);
//  }
//    printf("\n");

// OBSERVE THE DIFFERENCE

// 2)
//  static int j=5;
// if (--j){
//     printf("%d ",j);
//     main();
// }

// 3)PROBLEM
// int x = 5;
// int * const ptr = &x;
//++(*ptr);
// printf("%d", x);

// 4)
// int x = 5;
// int const * ptr = &x;
//++(*ptr);
// printf("%d", x);
// return 0;    //-->COMPILATION ERROR since constant value CANNOT be changed

// 5)PROBLEM
//  typedef static int *i;
// int j;
// i a = &j;
// printf("%d", *a);       //-->COMPILATION ERROR since muliple storage classes for a(typedef and static both are types of storage classes)

// 6)
// OBSERVE THE DIFFERENCE BETWEEN THIS AND THE EARLIER ONE
// typedef int i;
//  i a = 0;
//  printf("%d", a);

// 7)PROBLEM
// typedef int *i;
// int j = 10;
//// i *a = &j;
//// printf("%d", **a); //-->COMPILATION ERROR
// i a = &j;
// i b = &a;
// printf("%d\n", *a);
// printf("%d", **b);

// 8)A VERY GOOD QUESTION
//    int fun()
//{
//  static int num = 16;
//  return num--;
//}
//
// int main()
//{
//  for(fun(); fun(); fun())
//    printf("%d ", fun());  //-->14 11 8 5 2




//9)A VERY IMPORTANT CONCEPT
//int x = 10; 
//  static int y = x; //will show error //even before running because in C,//static variables can only be //initialized using constant literals...
//   
//  if(x == y) 
//     printf("Equal"); 
//  else if(x > y) 
//     printf("Greater"); 
//  else
//     printf("Less"); 

return 0;
}

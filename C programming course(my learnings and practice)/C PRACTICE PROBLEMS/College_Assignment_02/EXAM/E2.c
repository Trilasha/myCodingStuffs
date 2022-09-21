#include <stdio.h>
//#include <conio.h>
//main()
//{
//   enum fruits {apple,orange,mango} ;
//   enum color {orange,red,pink};
//   enum fruits f;
//   enum color c;
//   f=apple;
//   c=pink;
//   printf("Thee value of apple is %d\n",f);
//   printf("Thee value of pink is %d\n",c);
//   getch();
//}
//#include <stdio.h>
//enum day {sunday = 1, tuesday, wednesday, thursday, friday, saturday};//can be inside the int main() also
//
//int main()
//{
//	enum day d = thursday;
//	printf("The day number stored in d is %d", d);
//	return 0;
//}
//Suppose int and return 0 are removed and getch(); is written before },then also result will be displayed but with two warnings


// Another example program to demonstrate working
// of enum in C
#include<stdio.h>

enum year{Jan, Feb, Mar, Apr, May, Jun, Jul,
		Aug, Sep, Oct, Nov, Dec};

int main()
{
//int i;                                   ...way1
//write i before ; in the declaration part ...way2
enum year i;                               //...way3                         
for (i=Jan; i<=Dec; i++)	
	printf("%d ", i);
		
return 0;
}

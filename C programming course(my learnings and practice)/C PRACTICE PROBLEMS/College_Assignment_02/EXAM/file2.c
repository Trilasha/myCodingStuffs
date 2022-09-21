//#include <stdio.h>
//int main()
//{
//    int c;
//    scanf("%d",&c);
//switch (c)
//{
//case 2:
//printf("hello");
//    break;
//
//default:
//printf("no");
//    break;
//}    
//    return 0;
//}
#include <stdio.h>

 int main()
 {

float x,sum,no_row;
int i,n;
printf("Input the value of x :");
scanf("%f",&x);
printf("Input number of terms : ");
scanf("%d",&n);
sum =1; no_row = 1;
for (i=1;i<n;i++)
{
  no_row = no_row*x/(float)i;
  sum =sum+ no_row;
}
printf("\nThe sum  is : %f\n",sum);
return 0;
 }

//int main()
//{
//	float x=0.12526;
//	printf("%f\n",x);
//	printf("%e\n",x);
//	printf("%g\n",x);
//	return 0;
//}

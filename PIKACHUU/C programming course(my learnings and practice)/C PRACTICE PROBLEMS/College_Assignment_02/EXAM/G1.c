   //float sum,n,term;
   //int count=1;
   //sum=0;
   //printf("Enter the value of n\n");
   //scanf("%f",&n);
   //term = 1.0/n;
   //while (count<=n)
   //{
   //   sum=sum+term;
   //   count++;
   //}
   //printf("Sum = %f\n",sum);
  //  printf("This is a\bgirl");
  //  printf("This is a girl");


//#include <stdio.h>
//int sum(int a,int b)
//{
//    int c;
//    c=a+b;
//    return c;
//}
//  main()
//{
//    int a,b;
//    scanf("%d %d",&a,&b);
//   printf("The sum is %d",sum(a,b));
//}

#include <stdio.h>
int func1(int count);
int main()
{
    int a,count;
    for (count=1;count<=5; ++count)
    {
        a=func1(count);
        printf("%d",a);
    }
    
}
func1(int x)
    {
        int y=0;
        y+=x;
        return(y);
    }
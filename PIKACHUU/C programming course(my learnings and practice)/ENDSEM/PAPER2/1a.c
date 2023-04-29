#include <stdio.h>
void concat(char *b,char *c,char *a)
{
    int nb=0;
   for (int i = 0;b[i]!='\0'; i++)
   {
       nb++;
   }

    int nc=0;
   for (int i = 0;c[i]!='\0'; i++)
   {
       nc++;
   }
   
    
      int i=nb;
      for (int j = 0;c[j]!='\0';i++,j++)
      {
          b[i]=c[j];
      }
      b[i]='\0';
     int nbn=0;
   for (int i = 0;b[i]!='\0'; i++)
   {
       nbn++;
   }
    for (int i = 0; i < nbn; ++i)
    {
       a[i]=b[i];
    }
    printf("%s",a);
}
int main()
{
    char a[100],b[100],c[100];
gets(b);
gets(c);
concat(b,c,a);

    return 0;
}
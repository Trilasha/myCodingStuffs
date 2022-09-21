/*
Allow user to enter two strings and then concatenate them by saying that str1 is a friend of str2
Two methods have
been described in the following program
*/

#include <stdio.h>
#include <string.h> //If the second method is used then no need of string.h
int main()
{
  //char str1[34];
  //gets(str1);
  //char str2[45];
  //gets(str2);
  //char str3[]=" is a friend of ";
  //puts(strcat(str1,strcat(str3,str2)));

  char str1[34];                              //Don't give \n
  scanf("%s", &str1);
  char str2[34];
  scanf("%s", &str2);
  printf("%s is a friend of %s", str1, str2);

  return 0;
}

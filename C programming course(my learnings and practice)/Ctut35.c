#include <stdio.h>
#include <string.h>

int main()
{
    char s1[]="harry";
    char s2[]="ravi";
    char s3[54];
    //puts(strcat(s1,s2));
    printf("The length of s1 is %d\n", strlen(s1));     //Since ravi is copied to harry so total length of s1 is 9 but s2 wil remain 4 otherwise s1 will be 5 if we comment out the previous one
    printf("The length of s1 is %d\n", strlen(s2));
   printf("The reversed string s1 is: \n");
   puts(strrev(s1));
   printf("The reversed string s2 is: \n");
   puts(strrev(s2));
  // s3=strcat(s1,s2); //this will be wrong since s3 is an array

   strcpy(s3 ,strcat(s1,s2));      //this wil now return yrrahivar because in the previous codes we have reversed both s1 and s2
   puts(s3);

   printf("The strcmp for s1, s2 returned is %d\n", strcmp(s1,s2));    //we should not  expect ASCII difference because as per C standards
                                                                       //either 0 or >0 or <0 value will be returned
                                                                       //not compulsory +-1 but can also return ASCII difference

    return 0;                                                          //why same character does not return 0???
}
//***Code for Q2***
#include <stdio.h>
#include <stdlib.h>
int main()
{
     FILE *fptr;
	 fptr = fopen("myfile5.txt","r");
    if (fptr == NULL){
       printf("Not able to open the file");
       exit(1);
   }
   fseek(fptr,0L, SEEK_END);//0 can also be written
   long int s=ftell(fptr);
   printf("The size of myfile5.txt is : %ld bytes",s);
   fclose(fptr);
    return 0;
}
// C program to find the size of file
//#include <stdio.h>
//
//long int findSize(char file_name[])
//{
//	// opening the file in read mode
//	FILE* fp = fopen(file_name, "r");
//
//	// checking if the file exist or not
//	if (fp == NULL) {
//		printf("File Not Found!\n");
//		return -1;
//	}
//
//	fseek(fp, 0L, SEEK_END);
//
//	// calculating the size of the file
//	long int res = ftell(fp);
//
//	// closing the file
//	fclose(fp);
//
//	return res;
//}
//
//// Driver code
//int main()
//{
//	char file_name[] = { "a.txt" };
//	long int res = findSize(file_name);
//	if (res != -1)
//		printf("Size of the file is %ld bytes \n", res);
//	return 0;
//}

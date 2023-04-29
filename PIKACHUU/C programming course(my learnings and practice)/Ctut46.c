//Solution to Ex7 present in Ctut44US.c
#include <stdio.h>
#include <string.h>   //No need to write this correct???
 typedef struct Driver
{
    char name[34];
    char dlNo[45];
    char route[47];
    int kms;
} std;


int main()
{
struct Driver d1,d2,d3;
printf("Enter the details of the driver no. 1:\n");
printf("Enter the name of the first driver\n");
scanf("%s", &d1.name);
printf("Enter the dl.no of the first driver\n");
scanf("%s", &d1.dlNo);
printf("Enter the route of the first driver\n");
scanf("%s", &d1.route);
printf("Enter the no. of kms of the first driver\n");
scanf("%d", &d1.kms);


printf("Enter the details of the driver no. 2:\n");
printf("Enter the name of the second driver\n");
scanf("%s", &d2.name);
printf("Enter the dl.no of the second driver\n");
scanf("%s", &d2.dlNo);
printf("Enter the route of the second driver\n");
scanf("%s", &d2.route);
printf("Enter the no. of kms of the second driver\n");
scanf("%d", &d2.kms);



printf("Enter the details of the driver no. 3:\n");
printf("Enter the name of the third driver\n");
scanf("%s", &d3.name);
printf("Enter the dl.no of the third driver\n");
scanf("%s", &d3.dlNo);
printf("Enter the route of the third driver\n");
scanf("%s", &d3.route);
printf("Enter the no. of kms of the third driver\n");
scanf("%d", &d3.kms);

printf("***Printing the information of the drivers***\n");
printf("For Driver no.1:\n Name is %s\n", d1.name);
printf("DL number is %s\n", d1.dlNo);
printf("Route is %s\n", d1.route);
printf("Kms is %d\n\v", d1.route);

printf("For Driver no.2:\n Name is %s\n", d2.name);
printf("DL number is %s\n", d2.dlNo);
printf("Route is %s\n", d2.route);
printf("Kms is %d\n\v", d2.route);

printf("For Driver no.3:\n Name is %s\n", d3.name);
printf("DL number is %s\n", d3.dlNo);
printf("Route is %s\n", d3.route);
printf("Kms is %d\n\v", d3.route);












return 0;


}
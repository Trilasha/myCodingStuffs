//***Code for Q9***
#include <stdio.h>
#include <stdlib.h>
struct employee
{
    int id;
    char name[25];
    int age;
};
int main()
{
    struct employee emp1, *emp2;
    emp2 = (struct employee *)malloc(sizeof(struct employee));
    printf("Employee No. 1--> Enter your id:\n");
    scanf("%d", &emp1.id);
    printf("Enter your name:\n");
    scanf("%s", &emp1.name);
    printf("Enter your age:\n");
    scanf("%d", &emp1.age);
    printf("Employee No. 2--> Enter your id:\n");
    scanf("%d", &emp2->id);
    printf("Enter your name:\n");
    scanf("%s", &emp2->name);
    printf("Enter your age:\n");
    scanf("%d", &emp2->age);

    printf("---------------------------------------------------------------------------------------\n");
    printf("                         DISPLAYING the entries for EMPLOYEE NO. 1:\n");
    printf("---------------------------------------------------------------------------------------\n");

    printf("ID -->%d\n", emp1.id);
    printf("NAME-->%s\n", emp1.name);
    printf("AGE-->%d\n", emp1.age);

    printf("---------------------------------------------------------------------------------------\n");
    printf("                         DISPLAYING the entries for EMPLOYEE NO. 2:\n");
    printf("---------------------------------------------------------------------------------------\n");

    printf("ID -->%d\n", emp2->id);
    printf("NAME-->%s\n", emp2->name);
    printf("AGE-->%d\n", emp2->age);

    return 0;
}
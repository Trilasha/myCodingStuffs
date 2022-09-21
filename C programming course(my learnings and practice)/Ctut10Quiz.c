#include <stdio.h>

/*
math and science - 45
science - 15
math - 15

print the type of gift you are giving them
*/

int main()
{
    int a;
    printf("Write the number of subjects in whuch you qualified(out of 2)\n");
    scanf("%d", &a);
    
    if (a>=2)
    {
        printf("Congratulations!You get a prize money of $45 since youhavequalified both the exams.\n");
    }

    else if (a>=1)
    {
        printf("Congratulations!You get a prize money of $15 since you have qualified only one exam.\n");
    
    }
    
   

    else
    {
        printf("Sorry!You do not receive any prize money as you failed to qualify atleast one exam.Better luck next time.\n1");
        
        
    }
    

    //let's try doing the above quiz in another way as learnt from the comment section of cwh

    int m, s;
    printf("Enter you scores in mathematics out of 100\n");
    scanf("%d", &m);
    printf("Enter you scores in science out of 100\n");
    scanf("%d", &s);

    if (m>=33 && s>=33)
    {
        printf("Congratulations!You have passed in both the exams and so receive a prize money of $45\n");
    }
    else if (m<33 && s>=33)
    {
        printf("You have qualified only in science and so you receive a prize money of $15\n");
    }

    else if (m>=33 && s<33)
    {
    
        printf("You have qualified only in mathematics and so you receive a prize money of $15\n");
    }
    
    //Let's try yet another method to solve this quiz

    int c;
    printf("Enter 1 if passed in mathematics,2 if passed in science and 3 if passed in both\n");
    scanf("%d", &c);

    if (c==1)
    {
        printf("You have qualified only in mathematics and so you receive a prize money of $15\n");
    }
    
    else if (c==2)
    {
       printf("You have qualified only in science and so you receive a prize money of $15\n");
    }
    
    else if (c==3)
    {
        printf("Congratulations!You have passed in both the exams and so receive a prize money of $45\n");
    }
    
    

    return 0;
}

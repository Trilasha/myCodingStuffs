//***Code for Q10***
#include <stdio.h>
#include <time.h>

int main()
{
    int num,i=1,choice;
    srand(time(NULL));
    num=rand()%100; //this will generate a random number between 1 and 100 each time
    printf("You have to make the correct guess of the number generated randomly by the computer within 10 trials to win otherwise you lose...\n");
    printf("Good luck and you may start now...\n");
do
{
   printf(" Make your guess(Trial no. %d) : ",i);
   scanf("%d", &choice);
   if (choice==num)
   {
      printf("HURRAH!!!YOU WON the game in trial no. %d.Yes,the random number was exactly the one that you guessed,i.e,%d\n",i,num);
      goto end;
   }
   else if (choice<num)
   {
       printf("ALAS!That's the wrong guess.\n");
       printf("Hint:The random number is greater than your guess\n");
       printf("\n");
   }
   else if (choice>num)
   {
       printf("ALAS!That's the wrong guess.\n");
       printf("Hint:The random number is smaller than your guess\n");
       printf("\n");
   }
   i++;
} while (i<=10);
printf("OOPS!10 trials are over.You lose the game...BETTER LUCK NEXT TIME");
    return 0;
end:
printf("YOU PLAYED VERY WELL...");
}
//-->
/*
srand() sets the seed which is used by rand to generate “random” numbers. If you don’t call srand before your first call to rand, it’s as if you had called srand(1) to set the seed to one. 
In short, srand() — Set Seed for rand() Function. */
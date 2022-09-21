/*
create stone,paper and scisssor game
Player 1: Stone
Player 2(Computer): Scissors -->Player one gets 1 point
Write a C program to allow user to play this game 3 times with the computer.Log the scores of the computer and the 
player.Display the name of the winner at the end 
Note:You have to display the name of the player during the game.take user;s name as an input from the user.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char a[34];

void player1()
{
    int pscore=0,cscore=0;
    int choice,i=1,var;
    while (i!=4)
    {
        printf("\v***ROUND %d***:\nPLAYER 1 gets the first turn\n%s...choose any one of the following:\n--0>For Stone\n--1>For Paper\n--2>for Scissor\n", i, a);
        scanf("%d", &choice);
        printf("Now PLAYER2's turn(Computer)\n");
        srand(time(NULL));
        var=rand()%3;
        printf("The computer chooses option %d\n",var);
        if (choice==0 && var==0)
        {
            printf("#######***ROUND %d results:***#######\n", i);
            printf("Both selected the same option,i.e,STONE and hence it's a TIE\n");
            printf(".......Both the players get 1 point each\n");
            pscore++,cscore++;
        }
        else if (choice==0 && var==1)
        {
            printf("#######***ROUND %d results:***#######\n", i);
            printf("Player 1 selected STONE and Player 2 selected PAPER\n");
            printf(".......PLAYER 2(Computer) wins Round %d and gets 1 point\n", i);
            cscore++;
        }
        else if (choice==0 && var==2)
        {
              printf("#######***ROUND %d results:***#######\n", i);
            printf("Player 1 selected STONE and Player 2 selected SCISSSOR\n");
            printf(".......Player 1(%s) wins Round %d and gets 1 point\n", a, i);
            pscore++;
        }
         else if (choice==1 && var==0)
        {
              printf("#######***ROUND %d results:***#######\n", i);
            printf("Player 1 selected PAPER and Player 2 selected STONE\n");
            printf(".......PLAYER 1(%s) wins Round %d and gets 1 point\n", a,i);
            pscore++;
        }
         else if (choice==1 && var==1)
        {
            printf("#######***ROUND %d results:***#######\n", i);
            printf("Both selected the same option,i.e,PAPER and hence it's a TIE\n");
            printf(".......Both the players get 1 point each\n");
            pscore++,cscore++;
        }
         else if (choice==1 && var==2)
        {
              printf("#######***ROUND %d results:***#######\n", i);
            printf("Player 1 selected PAPER and Player 2 selected SCISSOR\n");
            printf(".......PLAYER 2(Computer) wins Round %d and gets 1 point\n", i);
            cscore++;
        }
         else if (choice==2 && var==0)
        {
              printf("#######***ROUND %d results:***#######\n", i);
            printf("Player 1 selected SCISSOR and Player 2 selected STONE\n");
            printf(".......PLAYER 2(Computer) wins Round %d and gets 1 point\n", i);
            cscore++;
        }
         else if (choice==2 && var==1)
        { 
             printf("#######***ROUND %d results:***#######\n", i);
            printf("Player 1 selected SCISSOR and Player 2 selected PAPER\n");
            printf(".......PLAYER 1(%s) wins Round %d and gets 1 point\n", a, i);
            pscore++;
        }
         else if (choice==2 && var==2)
        {
            printf("#######***ROUND %d results:***#######\n", i);
            printf("Both selected the same option,i.e,SCISSOR and hence it's a TIE\n");
            printf(".......Both the players get 1 point each\n");
            pscore++,cscore++;
        }

        else
        {
            printf("Sorry!!!You made a wrong selection...\n");
            printf("Threfore,1 point will be awarded to PLAYER 2(Computer).");
            cscore++;
        }
        i++;
    }
    printf("\v");
    printf("....***After the end of all the 3 rounds:***....\n");
    printf("The total score of %s(PLAYER 1) is %d\n", a, pscore);
    printf("The total score of Computer(PLAYER 2) is %d\n\v", cscore);
if (pscore>cscore)
{
    printf("THE WINNER OF THE GAME IS %s(PLAYER1)\n", a);
    printf("***CONGRATULATIONS***\n");
}
else if (pscore<cscore)
{
    printf("THE WINNER OF THE GAME IS COMPUTER(PLAYER2)\n");
    printf("Sorry %s!Better Luck Next Time...\n", a);
}
else if (pscore==cscore)
{
  printf("ITS A DRAW...KUDOS TO BOTH THE PLAYERS FOR THEIR REMARKABLE PERFORMANCE\n");
}

}
int main()
{
    char des;
    int b;
    printf("*******Welcome to the game of STONE,PAPER AND SCISSOR*******\n");
    printf("Please enter your name:\n");
    scanf("%s", &a);
    printf("So ***%s***,you will be the Player1 and your opponent will be the computer(Player2)\n");
    printf("____RULES OF THE GAME____\n");
    printf("The  game will be played between 2 players and it will consist of 3 rounds.So,you will have 3 chances to win.\n");
    printf("In every round,you will have to choose 1 out of 3 available options:Stone,Paper or Scissor and in turn the computer will also choose one...\n");
    printf("Paper wins over Stone,Stone wins over Scissor,Scissor wins over paper\n");
    printf("For every win,1 point will be awarded.\n");
     printf("Finally after the completion of 3 rounds,the player with the maximum score will be declared as the WINNER OF THE GAME\n");
     printf("Are you ready for the game:PRESS 1 to begin or else 0 to discontinue\n");
     scanf("%d", &b);

switch (b)
{
case 1:
   player1();
   printf("\v");
   while (des!='n')
   {
   printf("Do you want to play the game again?\nPress y if yes and n for no...\n");
   scanf(" %c", &des);
   switch (des)
   {
   case 'y':
     player1();
       break;
   }
   case 'n':
   printf("***...YOU ARE OUT OF THE GAME NOW***\n");
   }
    break;
    case 0:
    printf("Hope to see you playing this game soon...");
    break;
}
    return 0;
}



//Solution by Harry bhai is given in Ctut56.c
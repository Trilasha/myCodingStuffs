/*
//Solution by Harry bhai
    You have to fill in values to a template letter.txt
    letter.txt looks somewhat like this:
    Thanks for purchasing {{item}} from our outlet{{outlet}}.
    Please visit our outlet{{outlet}} for any kind of problems.We plam to
    serve you again soon.
    You have to read this file and replace these values
    {{name}} - Harry;
    {{item}} - Table Fan
    {{outlet}} - Ram Laxmi fan outlet

    Use file functions in C to accomplish the same
    */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//this is a string
char *replaceWord(const char *str, const char *oldWord, const char *newWord)//Why * is given before replaceWord??? 
{
    char *resultString;
    int i, count = 0;
    int newWordlength = strlen(newWord);
    int oldWordlength = strlen(oldWord);
    //Lets count the number of times the old word occurs in the string
    for (i = 0; str[i] != '\0'; i++)
    {
        if (strstr(&str[i], oldWord) == &str[i])
        {
            count++;

            //Jump over this word
            i = i + oldWordlength - 1;
        }
    }
    //Making a new string to fit in the replaced words
    resultString = (char *)malloc(i + count * (newWordlength - oldWordlength) + 1);
    i = 0;
    while (*str)
    {
        //Compare the substring with result
        if (strstr(str, oldWord) == str)
        {
            strcpy(&resultString[i], newWord);
            i += newWordlength;
            str += oldWordlength;
        }
        else
        {
            resultString[i] = *str;
            i += 1;
            str += 1;
        }
    }
    resultString[i] = '\0';
    return resultString;
}

int main()
{

    FILE *ptr = NULL;
    FILE *ptr2 = NULL;

    ptr = fopen("bill.txt", "r");
    ptr2 = fopen("genBill.txt", "w");
    char str[200]; //This part can be even more optimised using DMA
    fgets(str, 200, ptr);
    printf("The bill template was: %s\n", str);
    //Call the replaceWord function and generate new str
    char *newStr;
    newStr = replaceWord(newStr, "{{item}}", "Table Fan");
    newStr = replaceWord(newStr, "{{outlet}}", "Ram laxmi fan Outlet");
    newStr = replaceWord(newStr, "{{name}}", "Harry");
    printf("The actual bill generated is: %s\n", newStr);
    printf("The generated bill has been written to the file genBill.txt\n");
    fprintf(ptr2, "%s", newStr); //On running the program,genBill.txt automatically got generated
    fclose(ptr);
    fclose(ptr2);
    return 0;
}
//Solution to Ctut22Ex3.c by Harry sir

#include <stdio.h>

int main()
{
    char input;
    float kmsToMiles = 0.621371;
    float inchesToFoot = 0.0833333;
    float cmsToInches = 0.393701;
    float poundToKgs = 0.453592;
    float inchesToMeters = 0.0254;
    float first, second;

    while (1)    //infinite while loop has been used that keeps on repeating the process unless q is pressed
    {
        printf("Enter the character. q to quit\n  1. kms to miles\n  2. inches to foot\n  3. cms to inches\n  4. pound to kgs\n  5. inches to meter\n");
        scanf(" %c", &input);   
        printf("The character is '%c'\n", input);   //character includes both alphabets and numbers

       
        switch (input)
        {
        case 'q':
            printf("Quitting the program...");
            goto end;
            break;
        case '1':
         printf("Enter quantity in terms of first unit\n");
        scanf("%f", &first);

            second = first * kmsToMiles;
            printf("%0.2fkms is equal to %0.2fmiles\n", first, second);
            break;

        case '2':
         printf("Enter quantity in terms of first unit\n");
        scanf("%f", &first);

            second = first * inchesToFoot;
            printf("%finches is equal to %ffoot\n", first, second);
           
            break;

        case '3':
         printf("Enter quantity in terms of first unit\n");
        scanf("%f", &first);

            second = first * cmsToInches;
            printf("%fcms is equal to %finches\n", first, second);
           
            break;

        case '4':
         printf("Enter quantity in terms of first unit\n");
        scanf("%f", &first);

            second = first * poundToKgs;
            printf("%fpound is equal to %fkgs\n", first, second);
           
            break;

        case '5':
         printf("Enter quantity in terms of first unit\n");
        scanf("%f", &first);

            second = first * inchesToMeters;
            printf("%finches is equal to %fmeters\n", first, second);
           
            break;

        default:
            break;
        }
    }
end:
    return 0;
}

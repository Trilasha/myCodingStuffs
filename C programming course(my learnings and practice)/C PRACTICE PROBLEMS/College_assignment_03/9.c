//***Code for Q9***
#include <stdio.h>
int main()
{
    long long int num, original_num;
    printf("Enter a number:\n");
    scanf("%lld", &num);
    int count0 = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0;
    int count5 = 0, count6 = 0, count7 = 0, count8 = 0, count9 = 0;
    original_num = num;
    while (num)
    {
        switch (num % 10)
        {
        case 0:
            count0++;
            break;
        case 1:
            count1++;
            break;
        case 2:
            count2++;
            break;
        case 3:
            count3++;
            break;
        case 4:
            count4++;
            break;
        case 5:
            count5++;
            break;
        case 6:
            count6++;
            break;
        case 7:
            count7++;
            break;
        case 8:
            count8++;
            break;
        case 9:
            count9++;
            break;
        }
        num /= 10;
    }
    printf("In your entered number,i.e,%lld:-\n", original_num);
    if (count0 != 0)
    {
        printf("The total occurrence of 0 is : %d\n", count0);
    }
    if (count1 != 0)
    {
        printf("The total occurrence of 1 is : %d\n", count1);
    }
    if (count2 != 0)
    {
        printf("The total occurrence of 2 is : %d\n", count2);
    }
    if (count3 != 0)
    {
        printf("The total occurrence of 3 is : %d\n", count3);
    }
    if (count4 != 0)
    {
        printf("The total occurrence of 4 is : %d\n", count4);
    }
    if (count5 != 0)
    {
        printf("The total occurrence of 5 is : %d\n", count5);
    }
    if (count6 != 0)
    {
        printf("The total occurrence of 6 is : %d\n", count6);
    }
    if (count7 != 0)
    {
        printf("The total occurrence of 7 is : %d\n", count7);
    }
    if (count8 != 0)
    {
        printf("The total occurrence of 8 is : %d\n", count8);
    }
    if (count9 != 0)
    {
        printf("The total occurrence of 9 is : %d\n", count9);
    }

    return 0;
}
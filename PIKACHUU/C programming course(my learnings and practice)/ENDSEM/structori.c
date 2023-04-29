#include <stdio.h>
int main()
{
    struct date{
        int month;
        char day;
        int year;
        char mon[30];
    };
    struct account{
      int acc_no;
      char acc_type;
      char name[30];
      float balance;
      struct date lastpayment;
    } oldcustomer,newcustomer;
    oldcustomer.balance=30;
    oldcustomer.lastpayment.month=12;
    oldcustomer.lastpayment.day='s';
    printf("%f\n",oldcustomer.balance);
    printf("%d\n",oldcustomer.lastpayment.month);
    printf("%c\n",oldcustomer.lastpayment.day);
    //To get a string say the person's name and month name
    oldcustomer.name[30]="Potato";
    printf("%s\n",oldcustomer.name);
    return 0;
}
//*******Dynamic Initialization of Objects Using constructors*******
#include <iostream>
using namespace std;
class BankDeposit
{
    int principal;
    int years;
    float interestrate;
    float returnvalue;

public:
    // BankDeposit() {}  //Created to make an object even if p,y and r values are not given ?????????                  //Blank Constructor//Must be created
    BankDeposit(int p, int y, float r); //r can be a value like 0.04
    BankDeposit(int p, int y, int r);   //r can be a value like 14
    void show();
};
BankDeposit::BankDeposit(int p, int y, float r)
{
    principal = p;
    years = y;
    interestrate = r;
    returnvalue = principal;
    for (int i = 0; i < y; i++)
    {
        returnvalue = returnvalue * (1 + interestrate);
    }
}
BankDeposit::BankDeposit(int p, int y, int r)
{
    principal = p;
    years = y;
    interestrate = float(r) / 100;
    returnvalue = principal;
    for (int i = 0; i < y; i++)
    {
        returnvalue = returnvalue * (1 + interestrate);
    }
}
void BankDeposit ::show()
{
    cout << "Principal value was " << principal << endl
         << ".return value after " << years << " is " << returnvalue << endl;
}

int main()
{
   // BankDeposit bd1, bd2, bd3; //Follow either this way or the other way as shown below
    int p, y, R;
    float r;
    cout << "Enter the value of p,y and r" << endl;
    cin >> p >> y >> r;
    BankDeposit bd1 = BankDeposit(p, y, r);
    bd1.show();
    cout << "Enter the value of p,y and R" << endl;
    cin >> p >> y >> R;
    BankDeposit bd2 = BankDeposit(p, y, R);
    bd2.show();

    return 0;
}
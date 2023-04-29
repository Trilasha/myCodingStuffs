///O(logy) same as the iterative approach
#include <iostream>
using namespace std;
long long int binary_exp(long long int x,long long int n,long long M)
{
    if(n==0)
    return 1;
    else if(n==1)
    return x%M;
    else
    {
        long long int temp=binary_exp(x,n/2,M);
        temp=(temp*temp)%M;
        if(n%2==0)//when the power is even
        return temp;
        else
        return ((x%M)*temp)%M;//when the power is odd
    }
}
int main()
{
long long int x = 250;
	long long int y = 50;
	long long int p = 13;
	cout << "Power is " << binary_exp(x, y, p);
    return 0;
}
//#include<iostream>
//using namespace std;
//
////******* A NON-tail-recursive function*******
//// The function is not tail
//// recursive because the value returned by fact(n-1) is used in
//// fact(n) and call to fact(n-1) is not the last thing done by fact(n)
//unsigned int fact(unsigned int n)
//{
//	if (n == 0) return 1;
//
//	return n*fact(n-1);
//}
//
//// Driver program to test above function
//int main()
//{
//	cout << fact(5);
//	return 0;
//}




//Similar output can be obtained using a tail recursive function




//******* A TAIL RECURSIVE FUNCTION *******
#include<iostream>
using namespace std;

// A tail recursive function to calculate factorial
unsigned factTR(unsigned int n, unsigned int a)
{
	if (n == 1) return a;

	return factTR(n-1, n*a);
}

// A wrapper over factTR
unsigned int fact(unsigned int n)
{
return factTR(n, 1);
}

// Driver program to test above function
int main()
{
	cout << fact(5);
	return 0;
}


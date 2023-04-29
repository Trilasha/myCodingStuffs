//this code will overflow for large value of x and y
/* Iterative Function to calculate (x^y) in O(log y) */
#include <iostream>
using namespace std;
int power(int x, int y)
{
	
	// Initialize answer
	int res = 1;
	
	// Check till the number becomes zero
	while (y)
	{
		
		// If y is odd, multiply x with result
		if (y % 2 == 1)
			res = (res * x);
			
		// y = y/2
		y = y >> 1;
		
		// Change x to x^2
		x = (x * x);
	}
	return res;
}

int main()
{
    int x,y;
    cin>>x>>y;
    cout<<power(x,y)<<endl;
    return 0;
}
//In one article--> https://www.scaler.com/topics/data-structures/binary-exponentiation/
//I got that the time complexity as O(y) for x to the power y
//in case of both the iterative and recursive approaches

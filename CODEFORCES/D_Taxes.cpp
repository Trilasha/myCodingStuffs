// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to check if n is prime
bool isPrime(int n)
{
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

// Function to count the minimum
// prime required for given sum N
void printMinCountPrime(int N)
{

	int minCount;

	// Case 1:
	if (isPrime(N)) {
		minCount = 1;
	}

	// Case 2:
	else if (N % 2 == 0) {
		minCount = 2;
	}

	// Case 3:
	else {

		// Case 3a:
		if (isPrime(N - 2)) {
			minCount = 2;
		}

		// Case 3b:
		else {
			minCount = 3;
		}
	}

	cout << minCount << endl;
}

// Driver Code
int main()
{
	int N = 100;

	// Function Call
	printMinCountPrime(N);
	return 0;
}

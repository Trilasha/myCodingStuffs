// https://www.geeksforgeeks.org/count-n-length-strings-consisting-only-of-vowels-sorted-lexicographically/



// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to count N-length strings
// consisting of vowels only sorted
// lexicographically
int findNumberOfStrings(int n)
{
	// Stores count of strings consisting
	// of vowels sorted lexicographically
	// of all possible lengths
	vector<vector<int> > DP(n + 1,
							vector<int>(6));

	// Initialize DP[1][1]
	DP[1][1] = 1;

	// Traverse the matrix row-wise
	for (int i = 1; i < n + 1; i++) {

		for (int j = 1; j < 6; j++) {

			// Base Case
			if (i == 1) {
				DP[i][j] = DP[i][j - 1] + 1;
			}

			else {
				DP[i][j] = DP[i][j - 1]
						+ DP[i - 1][j];
			}
		}
	}

	// Return the result
	return DP[n][5];
}

// Driver Code
int main()
{
	int N;
    cin>>N;

	// Function Call
	cout << findNumberOfStrings(N);

	return 0;
}

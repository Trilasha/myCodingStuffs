// C++ implementation of above approach
#include <bits/stdc++.h>
using namespace std;

// Finds reverse of given num x.
int reverseNum(int x)
{
	string s = to_string(x);
	reverse(s.begin(), s.end());
	stringstream ss(s);
	int rev = 0;
	ss >> rev;
	return rev;
}

bool isMysteryNumber(int n)
{
	for (int i=1; i <= n; i++)
	{
		// if found print the pair, return
		int j = reverseNum(i);
        cout<<i<<" "<<j<<endl;
		if (i + j == n)
		{
			cout << i << " " << j;
			return true;
		}
	}

	cout << "Not a Mystery Number";
	return false;
}

int main()
{
	int n = 181;
	isMysteryNumber(n);
	return 0;
}

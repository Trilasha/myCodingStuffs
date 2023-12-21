// C++ program to find smallest number whose 
// factorial contains at least n trailing 
// zeroes. 
#include<bits/stdc++.h> 
using namespace std; 

// Return true if number's factorial contains 
// at least n trailing zero else false. 
bool check(long long p, long long n) 
{ 
	long long temp = p, count = 0, f = 5; 
	while (f <= temp) 
	{ 
		count += temp/f; 
		f = f*5; 
	} 
	return (count >= n); 
} 

// Return smallest number whose factorial 
// contains at least n trailing zeroes 
long long findNum(long long n) 
{ 
	// If n equal to 1, return 5. 
	// since 5! = 120. 
	if (n==1) 
		return 5; 

	// Initialising low and high for binary 
	// search. 
	long long low = 0; 
	long long high = 5*n; 
	long long ans=-1;

	// Binary Search. 
	while (low <=high) 
	{ 
		long long mid = (low + high) >> 1; 

		// Checking if mid's factorial contains 
		// n trailing zeroes. 
		if (check(mid, n)) {
			ans=mid;
			high = mid-1;
		}
		else
			low = mid+1; 
	} 
	if(ans==-1) return -1;
	long long temp = ans, count = 0, f = 5; 
	while (f <= temp) 
	{ 
		count += temp/f; 
		f = f*5; 
	} 
	if(count>n) return -1;
	return ans;
} 

// driver code 
int main() 
{
	int q;
	cin>>q;
	while(q--){
		int n;
		cin>>n;
		cout << findNum(n) << endl; 
    }
	return 0; 
} 

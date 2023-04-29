#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n, i=0, sum = 0;
    cin >> n;
    while(n > 0)
    {
        int d = n % 10;
        if(d == 1)
        {
           sum = sum + d * pow(2, i);
           cout << sum << endl;
        }
        i += 1;
        n /= 10;
    }
    cout << sum << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    uint32_t n;
    int count = 0;
    cin >> n;
    while(n != 0)
    {
        if(n & 1)
        {
            count += 1;
        }
        n = n >> 1;
    }
    cout << count << endl;
}
//will print the divisors in the sorted order

#include <bits/stdc++.h>
using namespace std;
#define ll long long


void printdivisors(ll n)
{
    ll i;
    for(i=1;i*i<n;i++)
    if(n%i==0)
    cout<<i<<" ";
    for(;i>=1;i--)
    if(n%i==0)
    cout<<(n/i)<<" ";
}
int main()
{
printdivisors(15);
    return 0;
}

//i/p-->15
//o/p-->1 3 5 15
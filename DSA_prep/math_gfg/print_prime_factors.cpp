#include <bits/stdc++.h>
using namespace std;
#define ll long long
void printprimefactors(ll n)
{
    if(n<=1) return;
    while(n%2==0)
    {
        cout<<2;
        n=n/2;
    }
     while(n%3==0)
    {
        cout<<3;
        n=n/3;
    }
    for (ll i = 5; i*i<=n; i=i+6)
    {
        while (n%i==0)
        {
            cout<<i;
            n=n/i;
        }
        while(n%(i+2)==0)
        {
            cout<<i+2;
            n=n/(i+2);
        }
    }
    if(n>3)
    cout<<n;
    return;
}
int main()
{
    ll n;
    cin>>n;
    printprimefactors(n);
    return 0;
}

//i/p-->450
//o/p-->23355
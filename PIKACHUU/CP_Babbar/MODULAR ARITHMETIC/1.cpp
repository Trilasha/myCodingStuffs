/*
We will take two inputs from the user, a variable ‘x’ and a variable ‘y’, and we are supposed to print the value of (x! + y!) mod (10^{9} + 7)  .
*/
#include <iostream>
using namespace std;
const int M=1e9+7;
const int N=1e5+10;
long long fact[N];
int main()
{
    fact[0]=fact[1]=1;
    for (int i = 2; i<N; ++i)
    {
        fact[i]=(fact[i-1]*i)%M;
    }
    int x,y;
    cin>>x>>y;
    cout<<(fact[x]+fact[y])%M<<endl;
}
// 3 6 -> 726 correct
#include <iostream>
using namespace std;
const long long int M=1e9+7;
const int N=1e5+10;
long long fact[N];
long long int binary_exp(long long int x,long long int n)
{
    if(n==0)
    return 1;
    else if(n==1)
    return x%M;
    else
    {
        long long int temp=binary_exp(x,n/2);
        temp=(temp*temp)%M;
        if(n%2==0)//when the power is even
        return temp;
        else
        return ((x%M)*temp)%M;//when the power is odd
    }
}
int main()
{
    fact[0]=fact[1]=1;
    for (long long int i = 2; i<N; ++i)
    {
        fact[i]=(fact[i-1]*i)%M;
    }
    int q;
    cin>>q;
    while (q--)
    {
        int n,m;
        cin>>n>>m;
        long long int a1=fact[n+m-1]%M;
        long long int temp=((fact[m-1]%M)*(fact[n]%M))%M;
        long long int a2=binary_exp(temp,M-2);
        cout<<(a1*a2)%M<<endl;

    }
    return 0;
}
//Code passed all the test cases and has been submitted successfully
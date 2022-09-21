#include <bits/stdc++.h>
using namespace std;
/*
In the recursive program, the solution to the base case is provided and the solution of the bigger problem is expressed in terms of smaller problems. 

RECURSION ARE OF 4 TYPES(SENIORS):
-->direct
-->indirect
-->tail
-->non-tail

RECURSION ARE OF 2 MAIN TYPES:
-->DIRECT
      1)TAIL 2)HEAD 3)TREE/LINEAR 4>NESTED
-->INDIRECT
(Read from GFG) 
*/
void print(int n)
{
    if(n==0)
    return;
    cout<<n<<" ";
    print(n-1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    print(n);
    return 0;
}
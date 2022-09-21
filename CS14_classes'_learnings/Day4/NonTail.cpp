#include <bits/stdc++.h>  //NOT ABLE TO INTERPRET THE OUTPUT
using namespace std;
void print(int n)
{
    if(n==0)
    return;
    print(n-1);
    cout<<n<<" ";
    return; //not necessary to write
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


//The code given above can be understood from the code and theory given below(gfg)
/*
How memory is allocated to different function calls in recursion? 
When any function is called from main(), the memory is allocated to it on the stack. A recursive function calls itself, the memory for a called function is allocated on top of memory allocated to calling function and different copy of local variables is created for each function call. When the base case is reached, the function returns its value to the function by whom it is called and memory is de-allocated and the process continues

#include <bits/stdc++.h>
using namespace std;

void printFun(int test)
{
	if (test < 1)
		return;
	else {
		cout << test << " ";
		printFun(test - 1); // statement 2
		cout << test << " ";
		return;
	}
}

// Driver Code
int main()
{
	int test = 3;
	printFun(test);
}
OUTPUT-->3 2 1 1 2 3

Explaination-->
When printFun(3) is called from main(), memory is allocated to printFun(3) and a local variable test is initialized to 3 and statement 1 to 4 are pushed on the stack as shown in below diagram. It first prints ‘3’. In statement 2, printFun(2) is called and memory is allocated to printFun(2) and a local variable test is initialized to 2 and statement 1 to 4 are pushed in the stack. Similarly, printFun(2) calls printFun(1) and printFun(1) calls printFun(0). printFun(0) goes to if statement and it return to printFun(1). Remaining statements of printFun(1) are executed and it returns to printFun(2) and so on. In the output, value from 3 to 1 are printed and then 1 to 3 are printed. 



The memory stack has been shown in below diagram.
*/


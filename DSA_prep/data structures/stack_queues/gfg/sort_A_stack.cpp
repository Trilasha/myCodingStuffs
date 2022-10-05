//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */


//************************************* USING ANOTHER TEMPORARY STACK *******************************************
void SortedStack :: sort()
{
   //Your code here
   stack<int> temp;
   while(!s.empty())
   {
      int var=s.top();
      s.pop();
      while(temp.empty()==0 && temp.top()>var)
      {
          int var2=temp.top();
          temp.pop();
          s.push(var2);
      }
      temp.push(var);
   }
   s=temp;
   
}


//************************************* USING RECURSION METHOD *******************************************
void insert(stack<int> &s,int temp)
{
    if(s.empty() || s.top()<=temp)
    {
        s.push(temp);
        return;
    }
    int var=s.top();
    s.pop();
    insert(s,temp);
    s.push(var);
    return;
}
void SortedStack :: sort()
{
   //Your code here
  if(s.size()==1)
  return;
  int temp=s.top();
  s.pop();
  sort();
  insert(s,temp);
  return;
}


//both TC=n^2 and AS=n
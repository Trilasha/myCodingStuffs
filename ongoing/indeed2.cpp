#include<stdio.h>
#include<string.h>
#include<string>

using namespace std;
// Read only region start

int prisonerMove(int input1,int input2,int input3[])
{
    // Read only region end
	// Write code here
	int index=-1;
	for(int x=0;x<(input1-1);++x)
	{
		if(input3[x]!=0)
		{
			index=x;
			break;
		}
	}

	int cnt=0;
	for(int x=index;x<(input1-1);++x)
	{
		if(input3[x]==0)
		cnt++;
	}

	int sum=0;
	for(int x=0;x<(input1-1);++x)
	{
		sum+=input3[x];
	}

	int ans=(sum+cnt)*input2;
	return ans;
	throw "Function prisonerMove(int input1,int input2,int input3[]) not implemented. ";
}


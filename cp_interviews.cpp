// Find the max sum of subarray where all elements are distinct

// 1 2 3 1 4 5

// 1 1 1 2 2     2 3     3 3 

// 1 2 3 -10 2 3

// int max_subarray_sum(vector<int> v)
// {
// int ans=0;
// int var=int_MIN;
// for(int i=0;i<v.size();++i)
// {
// var=max(v[i],var+v[i]);
// ans=max(ans,var);
// }

// Return ans;
// }


// int max_sum(vector<int> v)
// {
// int ans=int_MIN;
// int sum;

//             for(int i=0;i<n;++i)
//             {
// 	set<int> s;
// 	s.insert(v[i]);
// 	sum=v[i];
// 	for(int j=i+1;j<n;++j)
// 	{

// 	if(s.find(v[j])==s.end())
// 	{
// 	sum+=v[j];
// ans=max(ans,sum);
// }
// else 
// break;
// }
// s.clear();
// }

// }





#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    vector<int> num={6,5};
    int n=num.size();
	int first_max=num[0];
	int second_max=num[0];
	int check=0;

	for(int x=0;x<n;++x)
	{
        check=0;
		if(num[x]>first_max)
		{
            first_max=num[x];
            check=1;
        }

        if((num[x]>second_max || first_max==second_max) && check==0)
        {
            second_max=num[x];
        }
    }


// for(int x=0;x<n;++x)
// {
// 	if(num[x]>second_max && num[x]<first_max)
// 		{
// 			second_max=num[x];
// }
// }


cout<<first_max<<" "<<second_max<<endl;

    return 0;
}
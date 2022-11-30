// Find the max sum of subarray where all elements are distinct

// 1 2 3 1 4 5

// 1 1 1 2 2     2 3     3 3 

// 1 2 3 -10 2 3

// Int max_subarray_sum(vector<int> v)
// {
// Int ans=0;
// Int var=INT_MIN;
// for(int i=0;i<v.size();++i)
// {
// var=max(v[i],var+v[i]);
// ans=max(ans,var);
// }

// Return ans;
// }


// Int max_sum(vector<int> v)
// {
// Int ans=INT_MIN;
// Int sum;

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




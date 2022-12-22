class Solution {
public:
//if &val is written then th eerror appears as:-
/*
Line 10: Char 22: error: non-const lvalue reference to type 'int' cannot bind to a temporary of type 'int'
    solve(i+1,n,nums,val^nums[i],sum);
*/


//tc--> ?
void solve(int i,int n,vector<int>& nums,int val,int &sum)
{
    if(i==n)
    {
        sum+=val;
        return;
    }
    solve(i+1,n,nums,val^nums[i],sum);
    solve(i+1,n,nums,val,sum);
}
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int sum=0,val=0;
        solve(0,n,nums,val,sum);
        return sum;
    }
};
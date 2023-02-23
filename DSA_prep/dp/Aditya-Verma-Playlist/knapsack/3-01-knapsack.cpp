//recursive code for knapsack
int knapsnack(int wt[],int val[],int w,int n)
{
    if(n==0 || w==0)
    return 0;
    if(wt[n-1]<=w)
    return max(val[n-1]+knapsnack(wt,val,w-wt[n-1],n-1),knapsnack(wt,val,w,n-1));
    else if(wt[n-1]>w)
    return knapsnack(wt,val,w,n-1);
}
//dp code for knapsack-memoization
//suppose--> n<=100,w<=1000
int t[102][1002];
memset(t,-1,sizeof(t));
int knapsnack(int wt[],int val[],int w,int n)
{
    if(n==0 || w==0)
    return 0;
    if(t[n][w]!=-1)
    return t[n][w];

    if(wt[n-1]<=w)
    return t[n][w]=max(val[n-1]+knapsnack(wt,val,w-wt[n-1],n-1),knapsnack(wt,val,w,n-1));

    else if(wt[n-1]>w)
    return t[n][w]=knapsnack(wt,val,w,n-1);
}
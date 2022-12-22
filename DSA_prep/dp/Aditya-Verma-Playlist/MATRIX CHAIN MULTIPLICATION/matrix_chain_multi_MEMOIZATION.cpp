//****BOTTOM UP DP****



int static t[1000][1000];
int solve(int arr[],int i,int j)
{
    if(i>=j)return 0;

    if(t[i][j]!=-1)
    return t[i][j];

    int mn=INT_MAX;
    for(int k=i;k<=j-1;++k)
    {
        tempans=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]+arr[k]+arr[j];
        if(tempsum<mn)
        {
            mn=tempsum;
        }
    }


    return t[i][j]=mn;
}

int main()
{
    memset(t,-1,sizeof(t));
    solve(arr,1,size-1);
}
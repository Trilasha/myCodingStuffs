// k=i to k=j-1 
// for(i to k)  for(k+1 to j)

// k=i+1 to k=j
// for(i to k-1)  for(k to j)

/*
STEPS:

find i j (BC)
find k loop sequence
calculate cost for tempans


*/


int solve(int arr[],int i,int j)
{
    if(i>=j)return 0;

    int mn=INT_MAX;
    for(int k=i;k<=j-1;++k)
    {
        tempans=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]+arr[k]+arr[j];
        if(tempsum<mn)
        {
            mn=tempsum;
        }
    }


    return mn;
}
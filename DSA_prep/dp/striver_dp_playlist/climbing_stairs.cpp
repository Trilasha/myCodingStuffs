//exactly the fibonacci code
int func(int ind)
{
    if(ind==0)return 1;
    if(ind==1) return 1;
    int left=func(ind-1);
    int right=func(ind-2);
    return left+right;
}
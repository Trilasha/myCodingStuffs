class Solution {
public:
    int reverseNum(int x)
{
     int a = 0;
        while(x>0){
            a*=10;
            a+=x%10;
            x/=10;
        }
        return a;
}
    bool sumOfNumberAndReverse(int num) {
        int n=num;
        if(n==0)
            return true;
         for (int i=1; i <= n; i++)
    {
        int j = reverseNum(i);
        if (i + j == n)
        {
            return true;
        }
    }
    return false;
    }
    cout<<reverseNum(1000);
};
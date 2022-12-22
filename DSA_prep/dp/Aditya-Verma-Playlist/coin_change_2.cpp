class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int sz=coins.size();
        int t[sz+1][amount+1];

        for(int x=0;x<=sz;++x)
        {
            for(int y=0;y<=amount;++y)
            {
                t[x][y]=(INT_MAX-1);
            }
        }

        //besides the general initialization, additionally the 2nd row has to be initialized

        for(int y=0;y<=amount;++y)
        t[0][y]=INT_MAX-1;

        for(int x=1;x<=sz;++x)
        t[x][0]=0;

        for(int y=0;y<=amount;++y)
        if(y%coins[0]==0)
        t[1][y]=y/coins[0];
        else
        t[1][y]=INT_MAX-1;


        //
        //now the general knapsack concept would start from the 3rd row(2)
        for(int x=2;x<=sz;++x)
        {
            for(int y=0;y<=amount;++y)
            {
                if(coins[x-1]<=y)
                {
                    t[x][y]=min(1+t[x][y-coins[x-1]],t[x-1][y]);
                }
                else
                t[x][y]=t[x-1][y];
            }
        }

        if(t[sz][amount]==(INT_MAX-1))
        return -1;

        return t[sz][amount];


    }
};
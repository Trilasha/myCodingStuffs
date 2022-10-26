class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int maxy=-1;
        int index=-1;
        int ct=0;
        int diff=0;
        // for(auto &i:logs)
        // {
        //     if(((i+1)[1]-(i)[1])>maxy)
        //     {
        //         maxi=((i+1)[1]-(i)[1]);
        //         index=i[0];
        //     }
        // }
       // if()
        // vector<pair<int,int>> vp;
        // vp.push_back({logs[0][0],logs[0][1]});
        for(int i=0;i<logs.size()-1;++i)
        {
            if((logs[i+1][1]-logs[i][1])>maxy)
            {
                maxy=(logs[i+1][1]-logs[i][1]);
                index=logs[i+1][0];
            }
            else if((logs[i+1][1]-logs[i][1])==maxy && index>logs[i+1][0])
            {
                maxy=(logs[i+1][1]-logs[i][1]);
                index=logs[i+1][0];
            }
        }
        if(logs[0][1]>maxy)
            return logs[0][0];
        else if(logs[0][1]==maxy && logs[0][0]<index)
            return logs[0][0];
        else
            return index;
        
        //145
//[[114,5],[115,7],[50,9],[105,11],[18,13],[47,16],[48,18],[39,19]]
        //114
        
        /*
        70
[[36,3],[1,5],[12,8],[25,9],[53,11],[29,12],[52,14]]
12

        */
    }
};

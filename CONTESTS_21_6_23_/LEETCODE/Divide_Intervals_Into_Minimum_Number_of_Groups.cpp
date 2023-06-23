class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
       vector<int> v(1e6+10,0);
        for(auto &i:intervals)
        {
            v[i[0]]++;
            v[i[1]+1]--;
        }
        int ans=0;
        //int set=0;
       for(int i=1;i<v.size();++i)
        {
            
            
                v[i]+=v[i-1];
                ans=max(ans,v[i]);
            
            //set=1;
        }
        return ans;
        
    }
};
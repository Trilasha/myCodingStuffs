class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        vector<string> v;
        for(auto &i:nums)
        {
            v.push_back(to_string(i));
        }
        for(auto &i:nums)
        {
            string ans="";
            int ori=i;
            while(ori!=0)
            {
                int modi=ori%10;
                ans.push_back(modi+'0');
                ori/=10;
            }
            string temp="";
            int chk=0;
            for(int j=0;j<ans.size();++j)
            {

                if(ans[j]!='0' || chk==1)
                {
                    chk=1;
                    temp.push_back(ans[j]);
                }
            }
            v.push_back(temp);
        }
        // for(auto &i:v)
        //     cout<<i<<" ";
        // cout<<endl;
        set<string> st;
        for(auto &i:v)
            st.insert(i);
        return st.size();
    }
};
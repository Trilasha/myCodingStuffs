class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        int n=queries[0].size();
        for(int i=0;i<queries.size();++i)
        {
            for(int j=0;j<dictionary.size();++j)
            {
                int diff=0;
                for(int k=0;k<n;++k)
                {
                    if(queries[i][k]!=dictionary[j][k])
                        diff++;
                }
                if(diff<=2)
                {
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
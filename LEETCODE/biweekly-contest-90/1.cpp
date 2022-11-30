class Solution {
public:
    string oddString(vector<string>& words) {
        string ans="";
        map<vector<int>,int> mp1;
        map<vector<int>,int> mp2;
        for(int i=0;i<words.size();++i)
        {
            vector<int> temp;
            for(int j=0;j<words[i].size()-1;++j)
            {
                temp.push_back(words[i][j+1]-words[i][j]);
            }
            mp1[temp]++;
            mp2[temp]=i;
        }
        
        for(auto &i:mp1)
        {
            if(i.second==1)
            {
                ans=words[mp2[i.first]];
            }
        }
        return ans;
    }
};
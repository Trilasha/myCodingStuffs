class Solution {
public:
    int partitionString(string s) {
        set<char> ss;
        int ct=0;
        for(int i=0;i<s.size();++i)
        {
            if(ss.find(s[i])!=ss.end())
            {
                ct++;
                ss.clear();
                ss.insert(s[i]);
            }
            else
            {
            ss.insert(s[i]);
            }
        }
       return ct+1;
        
    }
};
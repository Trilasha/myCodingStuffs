class Solution {
public:
    int countTime(string time) {
        vector<int> v;
        string s=time;
        if(s[4]=='?' && s[3]=='?')
            v.push_back(60);
        else
        {
        if(s[4]=='?' && s[3]!='?')
        {
            if(s[3]=='6')
                v.push_back(1);
            else
                v.push_back(10);
        }
         else if(s[3]=='?' && s[4]!='?')
        {
            if(s[4]=='0')
                 v.push_back(6);
            else
                 v.push_back(6);
        }
        }
                            
        ////
                           
        if(s[0]=='?' && s[1]=='?')
            v.push_back(24);
        else
        {
        if(s[0]=='?' && s[1]!='?')
        {
            if(s[1]<='3')
                v.push_back(3);
            else
                v.push_back(2);
        }
         else if(s[1]=='?' && s[0]!='?')
        {
            if(s[0]=='2')
                 v.push_back(4);
            else
                 v.push_back(10);
        }
        }
        int ans=1;
                            for(auto &i:v)
                            ans*=i;
                            return ans;
                            
        
    }
};
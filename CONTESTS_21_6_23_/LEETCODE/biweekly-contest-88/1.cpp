class Solution {
public:
    bool equalFrequency(string word) {
        map<char,int> mp;
        set<char> ss;
        for(int i=0;i<word.size();++i)
        {
            mp[word[i]]++;
            ss.insert(word[i]);
        }
        if(ss.size()==1)
            return true;
        //int ct=0;
        vector<int> v;
        set<int> s;
        for(auto &i:mp)
        {
           s.insert(i.second);
            v.push_back(i.second);
        }
        map<int,int> mpc;
        for(auto &i:mp)
            mpc[i.second]++;
        int diff=0;
        if(s.size()==1 && s.find(1)!=s.end())
            return true;
        else if((s.size()==1) || s.size()>2)
           return false;
        else 
        {
            sort(v.begin(),v.end());
            if(v[0]==1 && mpc[1]==1)
                return true;
            for(int i=1;i<v.size();++i)
            {
                if(v[i]-v[i-1]>1)
                    return false;
                else if(v[i]-v[i-1]==1 && mpc[v[i]]!=1)
                    return false;
            }
            return true;
        }
    }
};
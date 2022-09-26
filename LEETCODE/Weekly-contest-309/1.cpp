class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int i1=-1,i2=-1;char c;
        // set<int> s;
        map<char,int> mp;
        for(int i=0;i<s.size();++i)
        {
            if(mp.find(s[i])==mp.end() && s[i]!='*')
            {
            i1=i;
            //cout<<i1<<" ";
            //s.insert(i1);
            c=s[i];
            s[i]='*';
            i2=s.find(c);
           // cout<<i2<<endl;
            mp[c]=i2-i1-1;
            }
            
        }
       //  // for(auto &i:mp)
       //  // cout<<i.first<<" "<<i.second<<endl;
       // for(auto &i:mp)
       // {
       //     if(i.second!=distance[97-i.first])
       //         return false;
       // }
       //  return true;
        for(int i=0;i<distance.size();++i)
    {
        if(mp.find('a'+i)!=mp.end())
        {
            if(mp['a'+i]!=distance[i])
            return false;
        }
    }
    return true;
    }
};
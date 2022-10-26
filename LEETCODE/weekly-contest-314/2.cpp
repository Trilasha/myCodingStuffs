class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> v;
         v.push_back(pref[0]);
        for(int i=0;i<pref.size()-1;++i)
        {
        bitset<64> b(pref[i]);
        string s=b.to_string();
        bitset<64> b2(pref[i+1]);
        string g=b2.to_string();
            string ans="";
            for(int i=0;i<s.size();++i)
            {
                if(g[i]=='0')
                {
                    if(s[i]=='0')
                        ans+='0';
                    else
                        ans+='1';
                }
                else
                {
                  if(s[i]=='0')
                        ans+='1';
                    else
                        ans+='0';  
                }
            }
                    int val=0;
            reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();++i)
        {
            if(ans[i]=='1')
            val+=(int)pow(2,i);
        }
            v.push_back(val);
        }
        return v;
    }
};


/*
//Another logical approach 

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
      vector<int> ans;
        ans.push_back(pref[0]);
        for(int i=1;i<pref.size();++i)
        {
            ans.push_back(pref[i-1]^pref[i]);
        }
        return ans;
        }
};
*/
class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ct=0;
        int maxi=-1;
        int index=-1;
        
        for(int i=0;i<s.size();++i)
        {
            if(s[i]+1==s[i+1] && i!=s.size()-1)
                ct++;
            else
            {
                maxi=max(maxi,ct+1);
                ct=0;
            }
                
        }
        return maxi;
    }
};
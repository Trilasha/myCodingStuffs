class Solution {
public:
    int minimizeXor(int num1, int num2) {
     int n=  __builtin_popcountll(num2);
        bitset<64> b(num1);
        string s=b.to_string();
        string ans="";
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='1' && n!=0)
            {
                ans.push_back('1');
                n--;
            }else
                ans.push_back('0');
        }
        reverse(s.begin(),s.end());
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();++i)
        {
            if(s[i]=='0' && n!=0)
            {
                ans[i]='1';
                n--;
            }
        }
        int val=0;
        for(int i=0;i<ans.size();++i)
        {
            if(ans[i]=='1')
            val+=(int)pow(2,i);
        }
        return val;
    }
};
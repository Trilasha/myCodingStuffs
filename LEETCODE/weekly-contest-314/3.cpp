class Solution {
public:
    string robotWithString(string s) {
    multiset<char> ms;
    stack<char> st;
    string ans="";
    for (int i = 0; i < s.size(); i++)
    {
        ms.insert(s[i]);
    }
    for (int i = 0; i < s.size(); i++)
    {
        st.push(s[i]);
        ms.erase(ms.find(s[i]));
        while(!st.empty()  && st.top() <= *ms.begin())
        {
            ans.push_back(st.top());
            st.pop();
        }
    }
    if(st.empty())
    {
        return ans;
        
    }
    else
    {
        while (!st.empty())
        {
          ans.push_back(st.top());
            st.pop();
        }
         return ans;
    }
    
        
    }
};
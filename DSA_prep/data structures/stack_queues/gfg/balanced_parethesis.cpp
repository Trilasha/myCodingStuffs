#include<bits/stdc++.h>
using namespace std;

unordered_map<char,int> symbols={{'[',-1},{'(',-2},{'{',-3},{']',1},{')',2},{'}',3}};

bool is_balanced(string s){
    stack<char> st;
    for(char bracket:s)
    {
        if(symbols[bracket]<0)
        {
            st.push(bracket);
        }
        else
        {
            if(st.empty())
            {
                return 0;
            }
            char top=st.top();
            st.pop();

            if(symbols[top]+symbols[bracket]!=0)
            return 0;
        }

    }
    if(st.empty())
    return 1;

    return 0;
}

int main()
{
    cout<<is_balanced("[{}}]");
    return 0;
}
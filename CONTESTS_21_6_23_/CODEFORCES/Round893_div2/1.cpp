#include<bits/stdc++.h>
using namespace std;

int value(string s){
    stack<char>op;
    stack<int>num;
    for(auto i:s){

        if(i=='+'|| i=='-' || i=='/' || i=='*'){
            op.push(i);
        }else{
            num.push(i-'0');
        }

        while(op.size()>=1 and num.size()>=2){
            int x=num.top();
            num.pop();
            int y=num.top();
            num.pop();
            if(op.top()=='+'){
                num.push(x+y);
            }
            if(op.top()=='-'){
                num.push(x-y);
            }
            if(op.top()=='/'){
                num.push(x/y);
            }
            if(op.top()=='*'){
                num.push(x*y);
            }
            op.pop();
        }
    }

    if(op.size()>0 || num.size()>1){
        return -1;
    }

    return num.top();
}

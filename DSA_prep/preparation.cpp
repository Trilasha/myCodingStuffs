/*
Rohan: hey there how you doing

Naman: I am fine you tell

Rohan: me too
*/



#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> conversation={"Rohan: hey there how you doing", "Naman: I am fine you tell", "Rohan: me too"};
    map<string,int> word_count;

    int len=conversation.size();
    //cout<<len<<endl;
    string temp="";
    int check1=0;

    for(int x=0;x<len;++x)
    {
        check1=0;
        temp="";
        for(int var=0;var<conversation[x].size();++var)
        {
            if(check1==0 && conversation[x][var]!=':')
            temp+=conversation[x][var];
            if(conversation[x][var]==':')
            check1=1;
            else if(check1==1 && conversation[x][var]==' ')
            word_count[temp]++;

            //cout<<temp<<endl;
            //cout<<check1<<endl;
        }
    }


    for(auto &element:word_count)
    cout<<element.first<<"->"<<element.second<<endl;

    return 0;
}
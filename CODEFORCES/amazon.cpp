#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    char last='*';
    int ans=0;
    for(int i=0;i<s.size();++i){
        if(s[i]=='?') continue;
        if(last!=s[i] && last!='*')ans++;
        last=s[i];
    }
    cout<<ans<<endl;
    return 0;
}
 
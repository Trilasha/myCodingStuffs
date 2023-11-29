
#include<bits/stdc++.h>
using namespace std;

pair<int,int> initial={-1,-1};

pair<int,int> findPalindrome(int left,int right,string &s,vector<vector<pair<int,int>>> &store){
    if(left>right){
        return {0,1};
    }
    if(left==right){
        return {1,1};
    }
    if(store[left][right]!=initial) return store[left][right];
    pair<int,int> choiceLeft=findPalindrome(left+1,right,s,store);
    pair<int,int> choiceRight=findPalindrome(left,right-1,s,store);
    pair<int,int> choiceMid=findPalindrome(left+1,right-1,s,store);
    int ok=0;
    int ans=0;
    if(s[left]==s[right] && choiceMid.second==1){
        ans+=choiceMid.first+2;
        ok=1;
    }
    ans=max({ans,choiceLeft.first,choiceRight.first});
    return store[left][right]={ans,ok};
}
int main(){
    string s;
    cin>>s;
    int n=s.size();
    for(int x=0;x<n;++x){
        s[x]=tolower(s[x]);
    }
    vector<vector<pair<int,int>>> store(n+1,vector<pair<int,int>>(n+1,{-1,-1}));
    int length=findPalindrome(0,n-1,s,store).first;
    int index=0;
    for(int x=0;x<n;++x){
        if(store[0][x].first==length){
            index=x;
            break;
        }
    }
    string ans="";
    for(int x=index-length+1;x<=index;++x){
        ans+=s[x];
    }
    cout<<ans<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    string s;
    cin>>s;
    ll n;
    cin>>n;
    vector<ll> ans;
    set<char> st={'a','e','i','o','u'};
    for(ll i=0;i<(ll)s.size();++i){
        if(st.count(s[i])){
            n+=2;
        }else{
            n++;
        }
        ans.push_back(s[i]*n);
    }
    for(auto &i:ans)cout<<i<<" ";
    cout<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    for(auto &i:A)cin>>i;
    int B;
    cin>>B;
    unordered_set<int> st;
    unordered_map<int,int> mp;
    vector<int> ans;
    for(int x=0;x<B;++x){
        st.insert(A[x]);
    }
    ans.push_back(st.size());
    for(int x=B;x<A.size();++x){
        mp[A[x-B]]--;
        cout<<A[x-B]<<" "<<mp[A[x-B]]<<endl;
        if(mp[A[x-B]]==0){
            //cout<<"---"<<endl;
            st.erase(st.find(A[x-B]));
        }
        mp[A[x]]++;
        st.insert(A[x]);
        ans.push_back(st.size());
    }
    for(int i=0;i<ans.size();++i)cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
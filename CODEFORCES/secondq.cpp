#include<bits/stdc++.h>
using namespace std;



int main(){
    int k;
    cin>>k;
    int n;
    cin>>n;
    vector<int>v;
    vector<int>level(n+1);
    map<int,int> mp;
    int l=0,nodes=0;
    for(int i=0;i<(1<<(n+1))-1;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    for(int i=0;i<v.size();){
        int cnt=1<<l;

        for(int j=i;j<i+cnt;++j){
            if(v[j]==-1)continue;
            level[l]+=v[j];
            mp[v[j]]=l;
        }
        l++;
        i+=cnt;
    }

    int sum=0,par=-1;
    for(int i=0;i<v.size();i++){
        if(i==0) continue;
        int parent= (i-1)/2;
        if(v[i]==k) par=parent;
    }

    for(int i=0;i<v.size();i++){
        if(i==0) continue;
        int parent= (i-1)/2;
        if(parent==par and v[i]!=-1) sum+=v[i];
    }


    int ans=level[mp[k]]-sum;
    cout<<ans<<endl;

}
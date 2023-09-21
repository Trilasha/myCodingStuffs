#include<bits/stdc++.h>
using namespace std;

#define ll long long 

//Given an array "arr" of positive integers with length N, your goal is to achieve the maximum possible score by removing elements from either the beginning or the end of the array. The score for removing an element is calculated as:
//Score = (element to be removed)*(Number of elements remaining in the array before removing)+minimum element in the array before removing 

ll solve(ll left,ll right,vector<ll> &v,vector<vector<ll>> &dp,set<ll> st){

}
int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    inpv(v);
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,-1));
    multiset<ll> st;
    for(auto &i:v){
        st.insert(v);
    }
    cout<<solve(0,n-1,v,dp,st)<<endl;
    return 0;
}



class DSU{
    vector<ll> par,size;
public:
    ll tot_components;
    DSU(ll n){
        size.resize(n+1,1);
        par.resize(n+1);
        for(ll i=1;i<=n;++i)
        par[i]=i;
        tot_components=n;
    }
    ll findPar(ll node){
        if (node==par[node])
        return node;
        return par[node]=findPar(par[node]);
    }
    ll getsize(ll node){
        return size[findPar(node)];
    }
    void unite(ll u,ll v){
        ll ult_u=findPar(u);
        ll ult_v=findPar(v);
        if(ult_u==ult_v)return;
        if(size[ult_u]<size[ult_v]){
            size[ult_v]+=size[ult_u];
            par[ult_u]=ult_v;
        }else{
            size[ult_u]+=size[ult_v];
            par[ult_v]=ult_u;
        }
        tot_components--;
    }
};
 

#include<bits/stdc++.h>
using namespace std;


#define ll long long 

class Employee{
    public:
        ll id;
        string name;
        ll seniority;
        string manager;
        vector<string> employees;
};

class Data{
    public:
        vector<ll>val;
        vector<vector<ll>>store,tree;

        Data(vector<ll>vall,vector<vector<ll>>storee,vector<vector<ll>>treee){
            val=vall;
            store=storee;
            tree=treee;
        }
};

void dfs(ll node,ll parent,vector<ll> &dp,vector<ll> &val,vector<vector<ll>> &tree){
    for(auto &child:tree[node]){
        if(child!=parent){
            dp[node]+=val[child];
            // cout<<"----"<<endl;
            dfs(child,node,dp,val,tree);
        }
    }
}

ll recur(ll node,ll par,ll flag,ll sum,Data &data){
    //if(data.store[node][flag]!=-1) return data.store[node][flag];
    if(!data.tree[node].size()) return sum;
    for(auto &child:data.tree[node]){
        if(child==par)continue;
    if(flag){
        // int p=data.val[node],np=0;
        // for(auto child:data.tree[node]){
        //     if(child==par) continue;
        //     p+=recur(child,node,0,data);
        //     np+=recur(child,node,1,data);
        // }
        // return data.store[node][flag]=max(p,np);
        sum=recur(child,node,0,sum,data);
    }else{
        // int np=0;
        // for(auto child:data.tree[node]){
        //     if(child==par) continue;
        //     np+=recur(child,node,1,data);
        // }
        // return data.store[node][flag]=np;
        sum=max(recur(child,node,0,sum,data),recur(child,node,1,sum+data.val[child],data));
    }
    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    vector<Employee> adj(n+1);
    for(ll i=0;i<n;++i){
        cin>>adj[i+1].id>>adj[i+1].name>>adj[i+1].seniority>>adj[i+1].manager;
    }
    vector<vector<ll>> tree(n+1);
    vector<ll> val(n+1);
    map<string,ll> ids;
    ll root=0;
    for(ll i=1;i<=n;++i){
        ids[adj[i].name]=adj[i].id;
        val[adj[i].id]=adj[i].seniority;

        if(adj[i].manager=="-1"){
            root=adj[i].id;
        }else{
            tree[adj[i].id].push_back(ids[adj[i].manager]);
            tree[ids[adj[i].manager]].push_back(adj[i].id);
        }
    }
    vector<ll> dp(n+1);
    dfs(1,-1,dp,val,tree);

    vector<vector<ll>> store(n+1,vector<ll>(2,-1));
    Data data(val,store,tree);
    cout<<max(recur(1,0,1,data.val[1],data),recur(1,0,0,0,data))<<endl;
    return 0;
}
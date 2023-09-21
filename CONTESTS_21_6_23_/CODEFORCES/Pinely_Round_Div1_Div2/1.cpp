#include<bits/stdc++.h>
using namespace std;


int func(vector<vector<int>> &customers,vector<vector<int>> &shops){
    int n=customers.size();
    int m=shops.size();
    for(int x=0;x<n;++x){
        sort(customers[x].begin(),customers[x].end());
    }
    for(int x=0;x<m;++x){
        sort(shops[x].begin(),shops[x].end());
    }
    sort(customers.begin(),customers.end());
    sort(shops.begin(),shops.end());
}
int main(){
    int n,p;
    cin>>n>>p;
    vector<vector<int>> customers(n,vector<int>(p));
    for(int x=0;x<n;++x){
        for(int y=0;y<p;++y){
            cin>>customers[x][y];
        }
    }
    int a,b;
    cin>>a>>b;
    vector<vector<int>> shops(a,vector<int>(b));
    for(int x=0;x<a;++x){
        for(int y=0;y<b;++y){
            cin>>shops[x][y];
        }
    }
    cout<<func(customers,shops)<<endl;
    return 0;
}
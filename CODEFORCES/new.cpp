#include<bits/stdc++.h>
using namespace std;




bool isPrime(int n){
    if(n==1) return false;
    if(n==2 || n==3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5;i*i<=n;i=i+6)
    if(n%i==0 || n%(i+2)==0)
    return false;
    return true;
}



int solve(vector<int> a, vector<int>b,int sum){
    while(!a.empty() and !b.empty()){
        sum-=a.back();
        a.pop_back();
        sum-=b.back();
        b.pop_back();
    }
    if(!b.empty()){
        sum-=b.back();
    }
    if(!a.empty()){
        sum-=a.back();
    }
    return sum;
}



int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    vector<int>p,np;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(isPrime(v[i])){
            p.push_back(v[i]);
        }else{
            np.push_back(v[i]);
        }
        sum+=v[i];
    }
    sort(p.begin(),p.end());
    sort(np.begin(),np.end());
    cout<<min(solve(p,np,sum),solve(np,p,sum))<<endl;
}
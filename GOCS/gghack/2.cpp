//to find the maximum number of equal elements that can be achieved in a subsequence of the given array 
//provided each element can be added with a value that lies [-k,k]
//approach -> sort the array-> find the longest subarray with (mx-min)<=2k




#include <bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin>>q;
    while(q--){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int x=0;x<n;++x){
        cin>>v[x];
    }
    sort(v.begin(),v.end());
    int ans=0;
    int j=0;
    for(int i=0;i<n;++i){
        while(j<i && v[i]-v[j]>2*k){
            ++j;
        }
        ans=max(ans,i-j+1);
    }

    cout<<ans<<endl;
    }
    return 0;
}
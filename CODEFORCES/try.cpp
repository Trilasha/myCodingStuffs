#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=1010;
    int result=0;
    for(int i=0;i<5;++i){
        cout<<result<<" "<<n<<endl;
        result=result<<1;
        if(n&1) result++;
        n>>=1;
    }
    //cout<<result<<endl;
    return 0;
}
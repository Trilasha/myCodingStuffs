class Solution{   
public:
    long long int totalWays(int N){
        long long ans=1;
        for(int x=N;x>=1;x--){
            ans*=x;
        }
        return ans;
    }
};
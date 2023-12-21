    public:
    int maxAnd(int N, vector<int> A){
        int ans=0;
        int done=-1;
        int ind=-1;
        for(int x=31;x>=0;--x){
            int ok=0;
            for(int i=0;i<N;++i){
                if(!(A[i]&(1<<x)) && i!=done){
                    ind=i;
                    ok++;
                }
            }
            if(ok==0){
                ans+=(1<<x);
            }else if(ok==1 && done==-1){
                 ans+=(1<<x);
                 done=ind;
            }
            // cout<<ans<<endl;
        }
        return ans;
    }
};
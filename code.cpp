//find the length of the longest subarray with 1

int cnt=0;
        int j=0;
        n=temp.size();
        for(int i=0;i<n;++i){
            j=i+1;
            int cnt=1;
            while(j<n && temp[j]==temp[i]){
                j++;
            }
            ans=max(ans,j-i);
            i=j-1;
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
         
        

        "(((((*(*********((*(((((****"
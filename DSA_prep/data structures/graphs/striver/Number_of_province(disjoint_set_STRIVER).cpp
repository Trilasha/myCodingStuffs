class DisjointSet{
    vector<int> size,parent;
    public:
    DisjointSet(int n)
    {
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;++i)
        {
            parent[i]=i;
        }
    }

     int findPar(int node)
    {
        if(node==parent[node])
        return node;
        return parent[node]=findPar(parent[node]);
        //now the path compression comes into picture
    }


    void unionBySize(int u,int v)
    {
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else 
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
       
    }




};

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        //to return the number of unique parents' count (i.e, the number of bosses)
        
        DisjointSet ds(V+1);
        for(int i=0;i<V;++i)
       {
           for(int j=0;j<V;++j)
           {
               if(adj[i][j]==1)
               ds.unionBySize(i,j);
               //no need to give check--> i!=j -->because it will get returned only in the 3rd step of unionBySize function
           }
       }
       
       
       int cnt=0;
       for(int i=0;i<V;++i)
       {
           if(ds.findPar(i)==i)
           cnt++;
           
           /*
           or else if I wish not to make any recursive calls then I can  make the parent vector of the DisjointSet class public and then write
           if(ds.parent[i]==i)
           cnt++;
           */
       }
       return cnt;
    }
};
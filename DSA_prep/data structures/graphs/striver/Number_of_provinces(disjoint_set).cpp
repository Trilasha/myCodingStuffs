//////////////////// meek  //////////////////////////////

//considering 0-based node (starting)
class DisjointSet{
    public:
    vector<int> size,parent;
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
        vector<vector<int>> adjList(V+1);
        
        for(int i=0;i<V;++i)
       {
           for(int j=0;j<V;++j)
           {
               if(adj[i][j]==1 && i!=j)
               adjList[i].push_back(j);
           }
       }
       
       
       DisjointSet ds(V);
       
       for(int i=0;i<V;++i)
       {
           for(auto &j:adjList[i])
           {
               ds.unionBySize(i,j);
           }
       }
       
       vector<int> par(V);
       for(int i=0;i<V;++i)
       {
           par[i]=ds.findPar(i);
       }
       
       
       set<int> st;
       
       for(auto &i:par)
       st.insert(i);
       
       return st.size();
    }
};





//////////////////////////////////////  the modified second part if considered 1-based nodes  ///////////////////////////////////////


class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<vector<int>> adjList(V+1);
        
        for(int i=0;i<V;++i)
       {
           for(int j=0;j<V;++j)
           {
               if(adj[i][j]==1 && i!=j)
               adjList[i+1].push_back(j+1);
           }
       }
       
       
       DisjointSet ds(V+1);
       
       for(int i=1;i<=V;++i)
       {
           for(auto &j:adjList[i])
           {
               ds.unionBySize(i,j);
           }
       }
       
       vector<int> par(V+1);
       for(int i=1;i<=V;++i)
       {
           par[i]=ds.findPar(i);
       }
       
       
       set<int> st;
       
       for(int i=1;i<=V;++i)
       st.insert(par[i]);
       
       return st.size();
    }
};
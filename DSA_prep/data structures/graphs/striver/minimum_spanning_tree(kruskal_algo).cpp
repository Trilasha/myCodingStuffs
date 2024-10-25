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

class Solution
{
	public:
	//sc--> size parent vectors and the edges(:))   --> O(E)
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //even though bidirectional(repetition of edges) but it will not be considered after the first encounter
        vector<pair<int,pair<int,int>>> edges;
        
        
        //O(V+E)
        for(int i=0;i<V;++i)
        {
            for(auto &j:adj[i])
            {
                int node=i;
                int adjNode=j[0];
                int wt=j[1];
                edges.push_back({wt,{node,adjNode}});
                //(:))
            }
        }
        
        
        //O(ElogE)-->sorting 
        sort(edges.begin(),edges.end());
        
        int mstWt=0;
        
        DisjointSet ds(V);
        
        
        //O(E*4alpha*2)
        for(auto &i:edges){
            int weight=i.first;
            int u=i.second.first;
            int v=i.second.second;
            
            if(ds.findPar(u)!=ds.findPar(v))
            {
                mstWt+=weight;
                ds.unionBySize(u,v);
            }
        }
        return mstWt;
    }
};

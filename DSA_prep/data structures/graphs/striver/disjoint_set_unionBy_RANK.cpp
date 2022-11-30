//tc--> O(4*alpha)--> which is as good as constant time


#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank,parent;
    public:
    DisjointSet(int n)
    {
        //declaring the size as n+1 will work for both 0 and 1-based indexing
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;++i)
        {
            parent[i]=i;
        }
    }
    // int findPar(int node)
    // {
    //     if(node==parent[node])
    //     return node;
    //     return findPar[parent[node]];
    // }
    //this is the basic logarithmic concept

     int findPar(int node)
    {
        if(node==parent[node])
        return node;
        return parent[node]=findPar(parent[node]);
        //now the path compression comes into picture
    }


    void unionByRank(int u,int v)
    {
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u])
        {
            parent[ulp_v]=ulp_u;
        }
        else
        {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;

            // parent[ulp_u]=ulp_v;
            // rank[ulp_v]++;

            //both will be correct
        }
    }





};

int main()
{

    //can ven call for DisjointSet ds1(7),ds2(9); --> multiple objects can be created inside the DisjointSet class
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);

    //if 3 and 7 belong to the same component;
    if(ds.findPar(3)==ds.findPar(7))
    cout<<"SAME"<<endl;
    else
    cout<<"NOT SAME"<<endl;

    cout<<"-----------------------"<<endl;


    //
    ds.unionByRank(3,7);

    if(ds.findPar(3)==ds.findPar(7))
    cout<<"SAME"<<endl;
    else
    cout<<"NOT SAME"<<endl;





    return 0;
}

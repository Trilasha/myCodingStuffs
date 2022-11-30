//tc--> O(4*alpha)--> which is as good as constant time


#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> size,parent;
    public:
    DisjointSet(int n)
    {
        //declaring the size as n+1 will work for both 0 and 1-based indexing
        size.resize(n+1,1);
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
        //the following code will be applicable for both greater or equal
        else 
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
       
    }





};

int main()
{

    //can even call for DisjointSet ds1(7),ds2(9); --> multiple objects can be created inside the DisjointSet class

    //don't use a combo of rank and size --> use any one at a time 
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);

    //if 3 and 7 belong to the same component;
    if(ds.findPar(3)==ds.findPar(7))
    cout<<"SAME"<<endl;
    else
    cout<<"NOT SAME"<<endl;

    cout<<"-----------------------"<<endl;


    //
    ds.unionBySize(3,7);

    if(ds.findPar(3)==ds.findPar(7))
    cout<<"SAME"<<endl;
    else
    cout<<"NOT SAME"<<endl;





    return 0;
}

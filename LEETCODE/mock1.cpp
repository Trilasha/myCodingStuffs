#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n=8;
    int cnt=0;

    for(int i=1;i<=n;++i)
    {
        int ori=n;
        while(ori>1)
        {
            cnt++;
            ori/=2;
        }
    }

    cout<<cnt<<endl;
    return 0;
}

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
vector<int> dis(V,1e9);

dis[S]=0;
pq.push({0,S});

while(!q.empty())
{
    int node=pq.top().first;
    int distance=pq.top().second;
    pq.pop();
    for(auto &child:adj[node])
    {
        int child_node=child.first;
        int edgewt=child.second;
        if(distance+edgewt<dis[childnode])
        {
            dis[childnode]=ditance+edgewt;
            pq.push({dis[childnode],childnode});
        }
    }
}
return dis;






class Solution {
public:
    int chk=0;
    void dfs(vector<vector<pair<int,int>>> &adj,pair<int,int> &p,int &temp,int &target)
    {
        
        int node=p.first;
        int wt=p.second;
        for(auto &i:adj[node])
        {
            int n=i.first;
            int w=i.second;
            if(n==1)continue;
            if(n==target)
            {
                temp=min(temp,w);
                continue;
            }
            else
                dfs(adj,i,temp,target);
            
        }
        
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        
        for(int i=0;i<roads.size();++i)
        {
            int u=roads[i][0];
            int v=roads[i][1];
            int wt=roads[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        
        for(int i=1;i<=n;++i)
        {
            cout<<i<<"->";
            for(auto &j:adj[i])
            {
                cout<<j.first<<" "<<j.second<<"-- ";
            }
            cout<<endl;
        }
        vector<int> vis(n+1);
        int mini=INT_MAX;
        int target=n;
        
        int temp=INT_MAX;
        for(int i=0;i<adj[1].size();++i)
        {
            temp=adj[1][i].second;
            dfs(adj,adj[1][i],temp,target);
            mini=min(temp,mini);
        }
        
        return mini;
    }
};

/*
6
[[4,5,7468],[6,2,7173],[6,3,8365],[2,3,7674],[5,6,7852],[1,2,8547],[2,4,1885],[2,5,5192],[1,3,4065],[1,4,7357]]

correct=1885
getting 4065
*/
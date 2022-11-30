//https://leetcode.com/contest/weekly-contest-320/problems/minimum-fuel-cost-to-report-to-the-capital/
#define ll long long
class Solution {
public:
    
    ll dfs(vector<vector<int>> &adj,int node,int par,ll &ans,int seats)
    {
        ll count=0;
        for(auto &child:adj[node])
        {
            if(child==par)
                continue;
            count+=dfs(adj,child,node,ans,seats);
        }
        
        count++;
        ans+=(count/seats);
        if(count%seats!=0)
        ans++;
        return count;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<int>> adj(1e5+10);
        
        for(int i=0;i<roads.size();++i)
        {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        
        ll fuel=0;
        
        for(int i=0;i<adj[0].size();++i)
        {
            ll ans=0;
            dfs(adj,adj[0][i],0,ans,seats);
            fuel+=ans;
        }
        
        return fuel;
    }
};
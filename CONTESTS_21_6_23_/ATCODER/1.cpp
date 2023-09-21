int minCost(vector<vector<int>> &adj,int n,int source,int destination,int K){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> pq;
    pq.push({0,src});
    vectr<int> distance(n+1,INT_MAX);
    while(!pq.empty()){
        int steps=pq.top().first;
        int currentCity=pq.top().second;
        pq.pop();
        if(currentCity==destination) return steps;
        if(steps>distance[currentCity]) continue;
        if(steps>K+1) continue;
        for(auto &child:adj[currentCity]){
            
        }
    }
}
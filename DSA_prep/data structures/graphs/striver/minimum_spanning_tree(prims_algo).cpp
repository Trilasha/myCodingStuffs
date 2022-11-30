	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        //tc--> ElogE(E-no. of edges)
        //whenever we will put a node in the mst then only we will mark it as visited
        //since we aren't printing the mst so not taking the 'PARENT' node
        //the intuition is basically a 'GREEDY' algorithm
        //overall tc--> ElogE+ElogE == ElogE
        //overall sc--> O(E)+V  (//priotity_que +  visited array)
        
         priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
         
         pq.push({0,0});
         vector<int> vis(V,0);
         
         
         int sum=0;
         
         //max may run for E times
         while(!pq.empty())
         {
             //maximum size of the heap can be E so tc-->logE
             auto it=pq.top();
             int weight=it.first;
             int node=it.second;
             pq.pop();
             //
             if(vis[node])continue;
             
             //that means now the node (just popped out) has been added to the mst
             vis[node]=1;
             sum+=weight;
             
             
            //ElogE
            //(for both traversing and putting them in the priority queue)
             for(auto &i:adj[node])
             {
                 int edgeW=i[1];
                 int childNode=i[0];
                 if(!vis[childNode])
                 pq.push({edgeW,childNode});
             }
             
         }
         
         return sum;
    }
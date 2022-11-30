
//-------------------------------------------------
//SINGLE source shortest path algorithm------------
//-------------------------------------------------





//dijkstra's algorithm is not applicable on graphs having negative weight cycles
//not a single edgeWeight should be negative
//or else the loop will fall into infinite loop
//


//if negative weigths then runs into infite loop
//if negative cycles then gives tle because it keeps on minimizing the distance




//tc--> ElogV  --> E(no of edges) and V(no of nodes)



 
/*******  why priority_queue preferred over simple queue? *********
 * it reduces the number of paths traversed hence reduces the time complexity also
 * greedy approach to get the minimal distace everytime in priority_queue
 */
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    // priority_queue <ll, vector<ll>, greater<ll> > pq; 
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        //minheap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int> dis(V,1e9);
        
        dis[S]=0;
        pq.push({0,S});
        
        while(!pq.empty())
        {
            int distance=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto &i:adj[node])
            {
                int childNode=i[0];
                int edgeWeight=i[1];
                if(distance+edgeWeight<dis[childNode])
                {
                    dis[childNode]=distance+edgeWeight;
                    pq.push({dis[childNode],childNode});
                }
            }
        }
        return dis;
    }





//////////////////////////////////////////////////////// with queue also getting the same answer ////////////////////////////////////////////////////////////////////////////////
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    // priority_queue <ll, vector<ll>, greater<ll> > pq; 
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        queue<pair<int,int>> q;
        vector<int> dis(V,1e9);
        
        dis[S]=0;
        q.push({0,S});
        
        while(!q.empty())
        {
            int distance=q.front().first;
            int node=q.front().second;
            q.pop();
            for(auto &i:adj[node])
            {
                int childNode=i[0];
                int edgeWeight=i[1];
                if(distance+edgeWeight<dis[childNode])
                {
                    dis[childNode]=distance+edgeWeight;
                    q.push({dis[childNode],childNode});
                }
            }
        }
        return dis;
    }
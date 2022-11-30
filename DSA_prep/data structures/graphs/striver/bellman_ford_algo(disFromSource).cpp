///////////////////////////////////  theory  //////////////////////////////////////////

//---------SINGLE source shortest path algorithm----------
//--------------------------------------------------------


//can be used to detect negative cycles also(diffence wrt dijkstra)

//applicable "ONLY" in "...DIRECTED GRAPHS..."

//if undirected graph is given then chamge it to DG to implement bellman ford algo
//like 1---2 (5)  so we have 1--->2 (5) and 2--->1 (5)
//if a graph has any pathweight lesser than 0 then we can say that it has got a negative cycle

/*steps:-
1)relax all the steps n-1 times sequentially
2)relaxation of edges meaning-->

if(dis[u]+wt<dis[v])
dis[v]=dis[u]+w;

suppose if nodes are from 0 to 5 then n=6 so 5 iterations have to be performed



//******* some important questions *******

Q1)Why only n-1 iterations?

Q2)How to detect negative cycles in the given directed graphs?
---------------------------------------------------------------------------------------------------------------------------------------------------

*/











 public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        
        //V-1 iterations(V-1 iterations will finally give the shortest distance array in the worst case)
        
        
        //tc--> V*E (No. of vertices * No.of edges)
        //tc worse than dijkstra(which has ElogV)
        //speciality of bellman--> when graph has negative edgeWeights and when graph has negative cycles
        
        
        vector<int> dis(V,1e8);
        dis[S]=0;
        
        for(int i=0;i<V-1;++i)
        {
        for(auto &i:edges)
        {
            int u=i[0];
            int v=i[1];
            int wt=i[2];
            if(dis[u]!=1e8 && dis[u]+wt<dis[v])
            dis[v]=dis[u]+wt;
        }
        
        }
        
        
        //checking for the existence of negative cycles
         for(auto &i:edges)
        {
            int u=i[0];
            int v=i[1];
            int wt=i[2];
            if(dis[u]!=1e8 && dis[u]+wt<dis[v])
            return {-1};
        }
        return dis;
    }
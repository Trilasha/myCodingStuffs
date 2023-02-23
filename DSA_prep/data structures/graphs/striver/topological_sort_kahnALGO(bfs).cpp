public:
	//Function to return list containing vertices in Topological order. 
	//tc-->v+e
	//sc-->n


	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> indegree(V,0);
	    for(int i=0;i<V;++i)
	    {
	        for(auto &node:adj[i])
	        indegree[node]++;
	    }
	    
	    
	    queue<int> q;
	    vector<int> topo;
	    
	    for(int i=0;i<V;++i)
	    {
	        if(indegree[i]==0)
	        q.push(i);
	    }
	    
	    //since it's a DAG so some node will always be there in the queue
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto &child:adj[node])
	        {
	            indegree[child]--;
	            if(indegree[child]==0)
	            q.push(child);
	        }
	    }
	    return topo;
	    
	}

























// struct node{
// 	int data;
// 	struct node* next;
// }

// struct node* head;

// void insert()
// {
// 	struct node* ptr;
// 	ptr=(struct node)malloc(sizeof(struct node*));
// 	int item;
// 	scanf("%d",&item);
// 	ptr->data=item;
// 	if(head==NULL)
// 	{
// 		head=ptr;
// 		ptr->next=NULL;
// 		return;
// 	}
// }

// void delete()
// {

}
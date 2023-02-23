// public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    
	    
	    //tc-->n^3
	    //sc-->O(n^2)
	    
	    //same question can be solved in a much better tc using dijkstra by applying it on every node(provided negative cycle does not exist)
	    //tc will still remain as --> N*ElogV
	    
	    
	    int n=matrix.size();
	    
	    //assigning 1e9 to the ones with no edges for our ease
	    for(int i=0;i<n;++i)
	    {
	        for(int j=0;j<n;++j)
	        {
	            if(matrix[i][j]==-1)
	            matrix[i][j]=1e9;
	        }
	    }
	    
	    
	    for(int val=0;val<n;++val)
	    {
	       for(int i=0;i<n;++i)
	       {
	           for(int j=0;j<n;++j)
	           {
	               matrix[i][j]=min(matrix[i][j],matrix[i][val]+matrix[val][j]);
	           }
	       }
	    }
	    
	    
	    //checking for the existence of negative cycle
	    for(int i=0;i<n;++i)
	    {
	        if(matrix[i][i]<0)
	        {
	        //then give the condition
	        }
	    }
	    
	    //do not forget to reverse our assumption
	      for(int i=0;i<n;++i)
	    {
	        for(int j=0;j<n;++j)
	        {
	            if(matrix[i][j]==1e9)
	            matrix[i][j]=-1;
	        }
	    }
	}
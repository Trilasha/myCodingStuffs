//////////////////// meek ////////////////////////////////
public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
                     
        vector<vector<int>> matrix(n,vector<int>(n,1e9));
      for(auto &i:edges)
        {
            matrix[i[0]][i[1]]=i[2];
            matrix[i[1]][i[0]]=i[2];
        }
        
        //int nn=matrix.size();
	    
	   // //assigning 1e9 to the ones with no edges for our ease
	   // for(int i=0;i<n;++i)
	   // {
	   //     for(int j=0;j<n;++j)
	   //     {
	   //         if(matrix[i][j]==-1)
	   //         matrix[i][j]=1e9;
	   //     }
	   // }
// 	     for(int i=0;i<n;++i)
// 	  {
// 	      for(auto &j:matrix[i])
// 	      {
// 	          cout<<j<<" ";
// 	      }
// 	      cout<<endl;
// 	  }
// 	  cout<<endl;
// 	  cout<<endl;
	    
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
	    
// 	       for(int i=0;i<n;++i)
// 	  {
// 	      for(auto &j:matrix[i])
// 	      {
// 	          cout<<j<<" ";
// 	      }
// 	      cout<<endl;
// 	  }
// 	  cout<<endl;
// 	  cout<<endl;
	    //checking for the existence of negative cycle
	       for(int i=0;i<n;++i)
	    {
	        for(int j=0;j<n;++j)
	        {
	            if(matrix[i][j]>distanceThreshold)
	            matrix[i][j]=1e9;
	        }
	    }
	    
	    vector<vector<int>> permissible_edges(n,vector<int>());
	    //map<int,int> mp;
	    
	    //do not forget to reverse our assumption
	      for(int i=0;i<n;++i)
	    {
	        for(int j=0;j<n;++j)
	        {
	            if(matrix[i][j]!=1e9 && i!=j)
	            permissible_edges[i].push_back(j);
	        }
	    }
	    
	    
	   int ans=n-1;
	   
	   int ct=n;
	   
	  for(int i=0;i<n;++i)
	  {
	      if(permissible_edges[i].size()==0)
	      {
	          ct=0;
	          ans=i;
	      }
	      else 
	      {
	          for(auto &j:permissible_edges[i])
	      {
	          if(permissible_edges[i].size()<=ct)
	          {
	              ct=permissible_edges[i].size();
	              ans=i;
	          }
	      }
	      
	      }
	  }
	  
// 	    for(int i=0;i<n;++i)
// 	  {
// 	      for(auto &j:permissible_edges[i])
// 	      {
// 	          cout<<j<<" ";
// 	      }
// 	      cout<<endl;
// 	  }
// 	  cout<<ct<<endl;
// 	  cout<<ans<<endl;
           
    return ans;          
    }


//////////////////////////////////////////////////////////  formatted one ////////////////////////////////////////////////////////////////

public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
                     
        vector<vector<int>> matrix(n,vector<int>(n,1e9));
      for(auto &i:edges)
        {
            matrix[i[0]][i[1]]=i[2];
            matrix[i[1]][i[0]]=i[2];
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
	    
	       for(int i=0;i<n;++i)
	    {
	        for(int j=0;j<n;++j)
	        {
	            if(matrix[i][j]>distanceThreshold)
	            matrix[i][j]=1e9;
	        }
	    }
	    
	    
	    
	    
	    vector<vector<int>> permissible_edges(n,vector<int>());
	      for(int i=0;i<n;++i)
	    {
	        for(int j=0;j<n;++j)
	        {
	            if(matrix[i][j]!=1e9 && i!=j)
	            permissible_edges[i].push_back(j);
	        }
	    }
	    
	    
	   int ans=n-1;
       //int ans=0 -->both will be correct
	   int ct=n;
	   
	  for(int i=0;i<n;++i)
	  {
	      if(permissible_edges[i].size()==0)
	      {
	          ct=0;
	          ans=i;
	      }
	      else 
	      {
	          for(auto &j:permissible_edges[i])
	      {
	          if(permissible_edges[i].size()<=ct)
	          {
	              ct=permissible_edges[i].size();
	              ans=i;
	          }
	      }
	      
	      }
	  }
	  
    return ans;          
    }


/////////////////////////////////////////////////////////////////   striver  ////////////////////////////////////////////////////////////////////////////////
public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
                     
      vector<vector<int>> matrix(n,vector<int>(n,INT_MAX));
      for(auto &i:edges)
        {
            matrix[i[0]][i[1]]=i[2];
            matrix[i[1]][i[0]]=i[2];
        }
        
        for(int i=0;i<n;++i)
        matrix[i][i]=0;
        
	    for(int val=0;val<n;++val)
	    {
	       for(int i=0;i<n;++i)
	       {
	           for(int j=0;j<n;++j)
	           {
	               if(matrix[i][val]==INT_MAX || matrix[val][j]==INT_MAX)
	               continue;
	               matrix[i][j]=min(matrix[i][j],matrix[i][val]+matrix[val][j]);
	           }
	       }
	    }
	    
	   //    for(int i=0;i<n;++i)
	   // {
	   //     for(int j=0;j<n;++j)
	   //     {
	   //         if(matrix[i][j]>distanceThreshold)
	   //         matrix[i][j]=1e9;
	   //     }
	   // }
	   // vector<vector<int>> permissible_edges(n,vector<int>());
	   
	   int cntCity=n;
	   int city_no=-1;
	   int ct=0;
	      for(int i=0;i<n;++i)
	    {
	        ct=0;
	        for(int j=0;j<n;++j)
	        {
	            if(matrix[i][j]<=distanceThreshold)
	            ct++;
	        }
	        if(ct<=cntCity)
	        {
	            cntCity=ct;
	            city_no=i;
	        }
	    }
	    
	    
// 	   int ans=0;
// 	   int ct=n;
	   
// 	  for(int i=0;i<n;++i)
// 	  {
// 	      if(permissible_edges[i].size()==0)
// 	      {
// 	          ct=0;
// 	          ans=i;
// 	      }
// 	      else 
// 	      {
// 	          for(auto &j:permissible_edges[i])
// 	      {
// 	          if(permissible_edges[i].size()<=ct)
// 	          {
// 	              ct=permissible_edges[i].size();
// 	              ans=i;
// 	          }
// 	      }
	      
// 	      }
// 	  }
	  
    return city_no;          
    }
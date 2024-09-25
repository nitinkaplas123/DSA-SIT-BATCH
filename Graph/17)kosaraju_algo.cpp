Steps-:
1)Order the vertex in decreasing order of finish time in DFS.
  Means the vertex which is finish last will be at top and so on.
2)Reverse all the edges.
3)Do DFS of the reversed graph in the order obtained in step1. For every vertex 
  print all reachable vertex as one strongly connected component.

Code-:
void topo_sort(vector<vector<int>>& adj,int V,bool visited[],int s,stack<int>&st)
	{
	    visited[s]=true;
	    for(auto x:adj[s])
	    {
	        if(visited[x]==false)
	        topo_sort(adj,V,visited,x,st);
	    }
	    st.push(s);
	}
	
	void topo(vector<vector<int>>& adj,int V,stack<int>&st)
	{
	   
	    bool visited[V]={false};
	    for(int i=0;i<V;i++)
	    {
	        if(visited[i]==false)
	        topo_sort(adj,V,visited,i,st);  
	    }
	}
	
	void reverse(vector<vector<int>>& adj,int V,vector<int>transpose[])
	{
	   for(int i=0;i<V;i++)
	   {
	     for(auto x:adj[i])
	     {
	      transpose[x].push_back(i);
	     }
	   }
	}
	
	void helper(vector<int>transpose[],int V,bool visited2[],int s)
	{
	    visited2[s]=true;
	    for(auto x:transpose[s])
	    {
	        if(visited2[x]==false)
	        helper(transpose,V,visited2,x);
	    }   
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
       stack<int>st;
       topo(adj,V,st);
       
       
       int topo_arr[V];
       int i=0;
       while(st.empty()==false)
       {
           int u=st.top();
           st.pop();
           topo_arr[i++]=u;
       }
      
       
       vector<int>transpose[V];
       reverse(adj,V,transpose);
       
       
       bool visited2[V]={false};
       int count=0;
       for(int i=0;i<V;i++)
       {
          int val=topo_arr[i];
          if(visited2[val]==false)
          {
              count++;
              helper(transpose,V,visited2,val);
          }
       }
       return count;
    }
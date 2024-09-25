https://www.geeksforgeeks.org/problems/topological-sort/1

Tetcase -:

  


Steps-:
1)here we use stack and visited array.
2)we call dfs from source if its not visited and then we call dfs of its adjacent 
  where it stops means that vertex indegree is highest from all so we push that 
  vertex into stack and so on.
3)At the end we have the elements in stack so we push every element into vector.
4)that vector order is our topo sort.



Code-:
void dfs(vector<int> adj[],vector<int>&visited,int s,stack<int>&st)
	{
	    visited[s]=true;
	    
	    for(auto x:adj[s])
	    {
	        if(visited[x]==false)
	        dfs(adj,visited,x,st);
	    }
	    st.push(s);
	    return ;
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>v;
	    stack<int>st;
	    
	    vector<int>visited(V,false);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(visited[i]==false)
	        dfs(adj,visited,i,st);
	    }
	    
	    while(st.empty()==false)
	    {
	        int top=st.top();
	        st.pop();
	        v.push_back(top);
	    }
	    return v;
	}
Steps-:
1)Intilaise dist[v]={INT_MAX};
2)dist[0]=0;
3)Find the topo_sort of the graph.
4)For every vertex u in the topo sort 
  a) for every adjacent v of u.
     if(dist[v]>dist[u]+wt(u,v))
     dist[v]=dist[u]+wt(u,v);

Code-:
void dfs(vector<pair<int,int>> adj[],vector<int>&visited,stack<int>&st,int s)
	 {
	    visited[s]=true;
	    
	    for(auto x:adj[s])
	    {
	        int v=x.first;
	        if(visited[v]==false)
	        dfs(adj,visited,st,v);
	    }
	    st.push(s);
	    return ;
	 }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N];
        for(int i=0;i<M;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
        }
        
        vector<int>visited(N,false);
        stack<int>st;
        for(int i=0;i<N;i++)
	    {
	        if(visited[i]==false)
	        dfs(adj,visited,st,i);
	    }
	    
	    vector<int>topo;
	    while(st.empty()==false)
	    {
	        topo.push_back(st.top());
	        st.pop();
	    }
	    
	    vector<int>dist(N,INT_MAX);
	    dist[0]=0;
	    
	    for(int i=0;i<N;i++)
	    {
	        int node=topo[i];
	        if(dist[node]!=INT_MAX)
	        {
	           for(auto x:adj[node])
	           { 
	            int v=x.first;
	            int wt=x.second;
	            if(dist[v]>dist[node]+wt)
	            dist[v]=dist[node]+wt;
	           }
	        }
	    }
	    for(int i=0;i<N;i++)
	    {
	        if(dist[i]==INT_MAX)
	        dist[i]=-1;
	    }
	    return dist;
    }



ChatGPT
The line if (dist[node] != INT_MAX) { // Only proceed if the node is reachable is essential 
for ensuring that the algorithm only attempts to relax edges from nodes that have already
been reached. Here’s why this condition is crucial:

Initial Condition: 
At the beginning of the algorithm, all distances are set to INT_MAX (representing infinity) except
for the source node, which is set to 0.

Unreachable Nodes: 
If a node has a distance of INT_MAX, it means that it has not been reached from the source node. 
Attempting to relax edges from such a node would be meaningless because there’s no valid path to it.

Relaxation Logic: 
The relaxation step is designed to update the shortest distance to each neighboring node based 
on the current shortest distance to the current node. If the current node's distance is INT_MAX, 
it means there’s no path to this node, and hence, there should be no attempt to propagate this 
invalid distance to its neighbors.
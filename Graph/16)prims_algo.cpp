Min spanning tree -> 
A spanning tree is defined as a tree-like subgraph of a connected,
undirected graph that includes all the vertices of the graph. Or, 
to say in Layman’s words, it is a subset of the edges of the graph 
that forms a tree (acyclic) where every node of the graph is a part
of the tree.

The minimum spanning tree has all the properties of a spanning tree with 
an added constraint of having the minimum possible weights among all 
possible spanning trees. Like a spanning tree, there can also be many
possible MSTs for a graph.

Minimum Spanning Tree (MST)

Properties of a Spanning Tree:
The spanning tree holds the below-mentioned principles:

1. The number of vertices (V) in the graph and the spanning tree is the same.
2. There is a fixed number of edges in the spanning tree which is equal to one less
   than the total number of vertices ( E = V-1 ).
3. The spanning tree should not be disconnected, as in there should only be a 
   single source of component, not more than that.
4. The spanning tree should be acyclic, which means there would not be any cycle 
   in the tree.
5. The total cost (or weight) of the spanning tree is defined as the sum of the
   edge weights of all the edges of the spanning tree.

Minimum Spanning Tree:
A minimum spanning tree (MST) is defined as a spanning tree that has the minimum 
weight among all the possible spanning trees.

Conclusion-:
A tree which having N nodes and N-1 edges and reachable from each other.



Code-:
int spanningTree(int V, vector<vector<int>> adj[])
{
      bool visited[V]={false};
      int dist[V];
      for(int i=0;i<V;i++)
      {
          dist[i]=INT_MAX;
      }
      dist[0]=0;
      
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
      
      pq.push({0,0});
      while(pq.empty()==false)
      {
          auto x=pq.top();
          pq.pop();
          int u=x.second;
          visited[u]=true;
          for(auto y:adj[u])
          {
            int vertex=y[0];
            int wt=y[1];
            if(visited[vertex]==false and (dist[vertex]>wt))
            {
                dist[vertex]=wt;
                pq.push({dist[vertex],vertex});
            }
          }
      }
      
      int sum=0;
      for(int i=0;i<V;i++)
      {
          sum+=dist[i];
      }
      return sum;
}
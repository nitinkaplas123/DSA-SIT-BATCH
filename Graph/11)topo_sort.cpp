https://www.geeksforgeeks.org/problems/topological-sort/1


Note -: topoSort is only for acyclic graph 
        if there is a cycle so we cannot find the topological sort.


1)Test case -:
0->1 
0->2 

o/p ->0 1 2 or 0 2 1

2)
0->2 0->3
1->3 1->4 

o/p -> 0 1 2 3 4 



Steps-:
1)Store inDegree of every vertex.
2)Create a queue q.
3)All all 0 degree vertex to the queue.
4)While(q.empty)
{
    a) val=q.front()
    b) print val.
    c) for every adj x of val 
       1)inDegree[x]--;
       2)if inDegree[x]==0
         add x to the queue.
}


Code-: O(V+E)
vector<int> topoSort(int V, vector<int> adj[]) 
{
	   vector<int>v;
	   vector<int>inDegree(V,0);
	   
	   for(int i=0;i<V;i++)
	   {
	       for(auto x:adj[i])
	       {
	           inDegree[x]++;
	       }
	   }
	   
	   queue<int>q;
	   for(int i=0;i<V;i++)
	   {
	       if(inDegree[i]==0)
	       q.push(i);
	   }
	   
	   while(q.empty()==false)
	   {
	       int val=q.front();
	       q.pop();
	       
	       v.push_back(val);
	       
	       for(auto x:adj[val])
	       {
	           inDegree[x]--;
	           if(inDegree[x]==0)
	           q.push(x);
	       }
	   }
	   return v;
}
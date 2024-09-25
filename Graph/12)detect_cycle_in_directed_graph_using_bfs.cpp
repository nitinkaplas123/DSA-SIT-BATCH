Steps-:
1)Do same as do in kahns algo.
2)As we known kahns algo is only for acyclic graph
  kahns algo cannot process cyclic graph.
3)while processing 
  1)if i am able to process every value from queue means its acyclic 
  2)else cylic.
4)so we use count variable 
  at the end if (count!=V) means cyclic  (where V is the no. of vertex)
  if equal means its acyclic.


Code-:
bool isCyclic(int V, vector<int> adj[]) {
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
        
        int count=0;
        while(q.empty()==false)
        {
            int val=q.front();
            q.pop();
            
            for(auto x:adj[val])
            {
                inDegree[x]--;
                if(inDegree[x]==0)
                q.push(x);
            }
            count++;
        }
        return (count!=V);
}
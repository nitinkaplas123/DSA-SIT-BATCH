Solution 1-:
Steps-:   (vector v, queue q , visited array )
1)Here we have to traverse the given undirected graph in bfs.
2)bFS means level order traversal.
3)As we know for bfs we use queue data struture here also we are using the same.
4)We know in unidirected graph we have multiple value of same because both are unidircted 
  for this problem we make -:
  visited[array] 
5)by traversing the value which are put into answer make that visited[value]=true so that in future we 
  cannot using this value.


Key points -:
1) the value which is added into q u have to add that into ans vector.
2)Now the value which is added into q will be checked first using visited array 
  if that value occur first time only then it will be pushed into queue.

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int>v;
        queue<int>q;
        vector<int>visited(V,false);
        
        q.push(0);
        visited[0]=true;
        
        while(q.empty()==false)
        {
            int val=q.front();
            q.pop();
            v.push_back(val);
            
            for(auto x:adj[val])
            {
                if(visited[x]==false)
                {
                    visited[x]=true;
                    q.push(x);
                }
            }
        }
        return v;
    }
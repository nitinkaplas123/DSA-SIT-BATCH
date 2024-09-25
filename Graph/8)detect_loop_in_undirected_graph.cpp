https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/0


Solution 1-:
Steps-:
1)here we use dfs and visited array to mark which is used.
2)here we use prev variable and src varible which tells us that src value ka prev value kya ha.
3)if we get prev value!=x (which is (adjacency)value of src) and visited[x]==true 
  it means there is a cycle because x is repeating element.



Code-:
bool dfs(vector<int>adj[],vector<int>&visited,int src,int prev)
{
        visited[src]=true;
        
        for(auto x:adj[src])
        {
            if(visited[x]==false)
            {
                if(dfs(adj,visited,x,src)==true)
                return true;
            }
            else if(visited[x]==true and x!=prev)
            return true;
            else
            continue;
        }
        return false;
}

bool isCycle(int V, vector<int> adj[]) {
        vector<int>visited(V,false);
        
        int prev=-1;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                if(dfs(adj,visited,i,prev)==true)
                return true;
            }
        }
        return false;
}


Sol-:2
Steps-:
1)using bfs method.

Code-:
bool bfs(vector<int>adj[],int s,int v,vector<int>&visited)
    {
       queue<int>q;
       q.push(s);
       visited[s]=true;
       vector<int>par(v,-1);
       
       while(q.empty()==false)
       {
           int val=q.front();
           q.pop();
           
           for(auto x:adj[val])
           {
               if(visited[x]==false)
               {
                   visited[x]=true;
                   q.push(x);
                   par[x]=val;
               }
               else if(x!=par[val])
               return true;
               else
               continue;
           }
       }
       return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>visited(V,false);
        int par=-1;
        
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                if(bfs(adj,i,V,visited)==true)
                return true;
            }
        }
        return false;
    }
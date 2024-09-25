Solution 1-:
Steps-:
1)Here we need shortest distance from source to every vertex.
2)So for shortest distance we do bfs because bfs goes from level to level
  and we get smallest distance using this.
3)Rest Code is same as of bfs.


0->1->2->3
0->2 and 1->3

Code-:
vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
       vector<int>ans(N,-1);
       vector<int>adj[N];
       
       for(int i=0;i<edges.size();i++)
       {
           int u=edges[i][0];
           int v=edges[i][1];
           adj[u].push_back(v);
           adj[v].push_back(u);
       }
       
       
       vector<int>visited(N,false);
       queue<int>q;
       q.push(src);
       visited[src]=true;
       ans[src]=0;
       
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
                   ans[x]=1+ans[val];
               }
           }
       }
       return ans;
}
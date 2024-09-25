Note -:
1)Its not working for -ve weight edges.
2) path change when all extra weight to all the edges.
Code-:
time complexity -> O(Elog(V)) E -> No. of edges. and V is the no. of vertex



Code-:
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
       vector<int>dist(V,1e9);
       dist[S]=0;
       priority_queue<pair<int,int>,vector<pair<int,int>>,
                      greater<pair<int,int>>>pq;
       pq.push({0,S});
       while(pq.empty()==false)
       {
           int dis=pq.top().first;
           int node=pq.top().second;
           pq.pop();
           
           for(auto x:adj[node])
           {
               int adjNode=x[0];
               int wt=x[1];
               if(dist[adjNode]>dist[node]+wt)
               {
                   dist[adjNode]=dist[node]+wt;
                   pq.push({dist[adjNode],adjNode});
               }
           }
       }
       return dist;
}


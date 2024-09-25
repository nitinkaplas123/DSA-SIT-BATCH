Question -> https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1



Making 
#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    int v=4;
    vector<int>adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    
    for(int i=0;i<v;i++)
    {
        for(auto x:adj[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}



Solution 1-:
Steps-:
1)Make a vector of size V.
2)Now if its a unidirected graph then we have to copy all the elements into vector adj[V].
3)Now traverse the adj vector list and print all the values accordingly.


Code-: Time-> O(V+E)  Space->O(V+E)
 vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++)
        {
            int val1=edges[i].first;
            int val2=edges[i].second;
            adj[val1].push_back(val2);
            adj[val2].push_back(val1);
        }
        return adj;
    }
Solution 1-:
Steps-:
1)dfs means going depth of current source.

void dfs(vector<int>adj[],vector<int>&visited,int s,vector<int>&ans)
{
        visited[s]=true;
        ans.push_back(s);
        
        for(auto x:adj[s])
        {
            if(visited[x]==false)
            dfs(adj,visited,x,ans);
        }
}
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        vector<int>visited(V,false);
        dfs(adj,visited,0,ans);
        return ans;
        
    }


Java -:
void dfs(ArrayList<ArrayList<Integer>> adj, boolean[] visited, int s, ArrayList<Integer> ans) {
        visited[s] = true;
        ans.add(s);

        for (int x : adj.get(s)) {
            if (!visited[x]) {
                dfs(adj, visited, x, ans);
            }
        }
}

public ArrayList<Integer> dfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
        ArrayList<Integer> ans = new ArrayList<>();
        boolean[] visited = new boolean[V];
        dfs(adj, visited, 0, ans);
        return ans;
}
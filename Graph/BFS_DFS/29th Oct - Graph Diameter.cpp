// Graph Diameter

class Solution {
  public:
  void dfs(int curr , int currDist , unordered_map<int , list<int>> &adj, vector<bool> &visited, vector<int> &dist){
       if(dist[0] < currDist){
           dist[0] = currDist; 
           dist[1] = curr ;
       }
       visited[curr] = true; 
       for(auto &nbr : adj[curr]){
           if(!visited[nbr]){
               dfs(nbr, currDist + 1, adj , visited, dist);
           }
       }
  }
  
    int diameter(int V, vector<vector<int>>& edges) {
        unordered_map<int , list<int>>adj; 
        
        for(auto &edge : edges){
            int u = edge[0];
            int v  = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
       vector<bool>visited(V + 1, false);
       vector<int>dist(2, 0);
       
       dfs(0, 0 , adj , visited, dist);
       int end1 = dist[1];
       
       vector<bool>visited1(V, false);
       dfs(end1 , 0 , adj , visited1 ,dist);
       return dist[0];
    }
};

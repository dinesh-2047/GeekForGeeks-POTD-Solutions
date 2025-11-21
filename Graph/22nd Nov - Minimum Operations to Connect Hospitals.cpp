// Minimum Operations to Connect Hospitals

class Solution {
  public:
  void dfs(int node , vector<bool> &visited, unordered_map<int ,list<int>> &adj){
      visited[node] = true; 
      
      for(auto &nbr : adj[node]){
          if(!visited[nbr]){
              dfs(nbr, visited, adj);
          }
      }
  }
  
    int minConnect(int V, vector<vector<int>>& edges) {
        if(edges.size() < V-1) return -1;
        unordered_map<int , list<int>>adj; 
        
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int result = 0 ; 
        vector<bool>visited(V ,false);
        for(int i = 0 ; i  <V; i++){
            if(!visited[i]){
            dfs(i,visited, adj);
            result++;
            }
        }
        return result - 1; 
        
    }
};

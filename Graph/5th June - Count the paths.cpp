// Count the paths


// DFS With DP 

class Solution {
  public:
  int dfs(unordered_map<int , list<int>> &adj , int V, int src, int dest, vector<int> &dp){
      if(src == dest) return 1; 
      
      if(dp[src]!=-1) return dp[src];
      
      int result = 0 ; 
      
      for(auto &nbr: adj[src]){
          result += dfs(adj , V ,nbr , dest,dp);
      }
      return dp[src] =  result; 
  }
  
  
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
       
      
       unordered_map<int , list<int>>adj; 
       
       for(auto &edge : edges){
           int u = edge[0];
           int v = edge[1];
           
           adj[u].push_back(v);
          
       }
       vector<int>dp(V+1, -1);
       
       return dfs(adj , V  ,src, dest,dp);
        
    }
};
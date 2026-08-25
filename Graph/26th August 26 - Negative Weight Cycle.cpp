// Negative Weight Cycle

class Solution {
  public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
      
      vector<int> dist(V, 1e9);
      
      int n = edges.size();
      
      for(int i = 0 ; i < V; i++){
          for(int j = 0;j < n; j++){
              int u = edges[j][0];
              int v = edges[j][1];
              int w = edges[j][2];
              
              if(dist[u] + w < dist[v]){
                  dist[v] = dist[u] + w; 
              }
          }
      }
      
      for(int j = 0 ;j  < n; j++){
          int u = edges[j][0];
          int v = edges[j][1];
          int w = edges[j][2];
          
          if(dist[u] + w < dist[v]) return true; 
      }
      return false; 
        
    }
};
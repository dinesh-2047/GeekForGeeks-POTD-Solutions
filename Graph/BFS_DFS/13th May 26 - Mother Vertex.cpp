// Mother Vertex

class Solution {
  public:
  unordered_map<int , list<int>> adj; 
  void dfs(vector<bool> &visited, int node){
      visited[node] = true; 

      for(auto &nbr : adj[node]){
          if(!visited[nbr]){
              dfs(visited, nbr);
          }
      }
  }
  
    int findMotherVertex(int V, vector<vector<int>>& edges) {
         for(auto &edge: edges){
             int u = edge[0];
             int v = edge[1];
             
             adj[u].push_back(v);
         }
         
       
        vector<bool> visited(V, false);
        int mother = -1; 
         for(int i = 0 ;i  < V; i++){
             if(!visited[i]){
             dfs(visited, i);
               mother = i ; 
             }
         }
        visited.assign(V, false);
        
        dfs(visited, mother);
        
       for(int i = 0 ; i  < V; i++){
           if(!visited[i]) return -1; 
       }
       return mother ; 
        
    }
};
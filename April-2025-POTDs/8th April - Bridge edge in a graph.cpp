// Bridge edge in a graph

class Solution {
    public:
    void dfs(unordered_map<int, list<int>> &adj , vector<bool> &visited, int node){
        visited[node] = true; 
        for(auto &nbr : adj[node]){
            if(!visited[nbr]){
                dfs(adj , visited, nbr);
            }
        }
    }
      int isBridge(int V, vector<vector<int>> &edges, int c, int d) {
          unordered_map<int , list<int>>adj ; 
          
          for(auto &edge : edges){
              int u = edge[0];
              int v = edge[1];
              
              adj[u].push_back(v);
              adj[v].push_back(u);
          }
          
          int component_before_removing = 0;
          vector<bool>visited(V, false);
          for(int i = 0; i<V; i++){
              if(!visited[i]){
                  component_before_removing++;
                  dfs(adj , visited, i);
              }
          }
          
          adj[c].remove(d);
          adj[d].remove(c);
          visited.clear();
          visited.resize(V,false);
          int component_after_removing = 0 ;
          
          for(int i = 0; i<V; i++){
              if(!visited[i]){
                  component_after_removing++;
                  dfs(adj , visited, i);
              }
          }
          
          if(component_after_removing > component_before_removing) return true; 
          else return false; 
          
      }
  };
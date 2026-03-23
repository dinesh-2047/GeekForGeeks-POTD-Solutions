// Length of Longest Cycle in a Graph

class Solution {
  public:
  unordered_map<int , list<int>>adj; 
  int cycle = -1; 
    vector<bool>visited;
     vector<int>dis;
     unordered_set<int>st; 
  void dfs(int node ){
      visited[node] = true; 
      st.insert(node);
      
      for(auto &nbr : adj[node]){
          if(!visited[nbr]){
              dis[nbr] = dis[node] + 1; 
              dfs(nbr);
          }
          else {
              if(st.count(nbr)){
                  cycle = max(cycle , abs(dis[nbr] - dis[node]) + 1);
              }
          }
      }
      st.erase(node);
      
  }
  
    int longestCycle(int V, vector<vector<int>>& edges) {
       
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
        }
        
      visited.assign(V, false);
        dis.assign(V, 0);
       
        for(int i = 0 ; i < V; i++){
            if(!visited[i]){
                  st.clear();
                dfs(i);
         
            }
        }
        return cycle; 
    }
};

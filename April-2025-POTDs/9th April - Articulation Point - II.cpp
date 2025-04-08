// Articulation Point - II


class Solution {
    public:
  
  // DFS function to find articulation points
  void dfs(unordered_map<int, list<int>> &adj, int node, vector<bool> &visited,
           vector<int> &disc, vector<int> &low, int parent, int &timer,
           vector<int> &ans, vector<bool> &isArticulation) {
      
      // Step 1: Mark the node as visited
      visited[node] = true;
  
      // Step 2: Initialize discovery and low time
      disc[node] = low[node] = timer;
      timer++;
  
      int child = 0; // count of child nodes (for root condition)
  
      // Step 3: Traverse all neighbors
      for (auto &nbr : adj[node]) {
  
          if (nbr == parent)
              continue; // Skip the parent node (from where we came)
  
          if (!visited[nbr]) {
              // Recursive DFS for unvisited neighbor
              dfs(adj, nbr, visited, disc, low, node, timer, ans, isArticulation);
  
              // After visiting, update the low time of current node
              low[node] = min(low[node], low[nbr]);
  
              // Step 4: Articulation point condition for non-root node
              if (low[nbr] >= disc[node] && parent != -1) {
                  isArticulation[node] = true;
              }
  
              child++; // Increment child count
          } else {
              // If neighbor is already visited and not parent, it's a back edge
              low[node] = min(low[node], disc[nbr]);
          }
      }
  
      // Step 5: Articulation point condition for root node
      if (parent == -1 && child > 1) {
          isArticulation[node] = true;
      }
  }
  
  vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
  
      // Step 1: Create adjacency list
      unordered_map<int, list<int>> adj;
      for (auto edge : edges) {
          int u = edge[0];
          int v = edge[1];
  
          adj[u].push_back(v);
          adj[v].push_back(u); // undirected graph
      }
  
      // Step 2: Initialize data structures
      vector<bool> visited(V, false);       // to track visited nodes
      vector<int> disc(V, -1);              // discovery time
      vector<int> low(V, -1);               // lowest discovery time reachable
      vector<bool> isArticulation(V, false);// to mark articulation points
      vector<int> ans;                      // final list of articulation points
  
      int timer = 0;
      int parent = -1; // initially, root has no parent
  
      // Step 3: Handle disconnected components
      for (int i = 0; i < V; i++) {
          if (!visited[i]) {
              dfs(adj, i, visited, disc, low, parent, timer, ans, isArticulation);
          }
      }
  
      // Step 4: Collect all articulation points
      for (int i = 0; i < V; i++) {
          if (isArticulation[i]) {
              ans.push_back(i);
          }
      }
  
      // Step 5: Return result
      if (ans.empty()) return {-1}; // if no articulation points
      return ans;
  }
  };
  
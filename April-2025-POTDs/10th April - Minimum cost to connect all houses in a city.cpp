// Minimum cost to connect all houses in a city


class Solution {
    public:
      // Function to calculate the minimum cost to connect all houses
      int minCost(vector<vector<int>>& houses) {
          int n = houses.size();  // Number of houses
  
          // Step 1: Create adjacency list representing a complete graph
          // Each edge connects two houses with the weight equal to their Manhattan distance
          // Time complexity: O(n^2)
          unordered_map<int, list<pair<int , int>>> adj; 
          for (int i = 0 ; i < n; i++) {
              for (int j = i + 1; j < n; j++) {
                  int x1 = houses[i][0];
                  int y1 = houses[i][1];
  
                  int x2 = houses[j][0];
                  int y2 = houses[j][1];
  
                  // Manhattan Distance = |x1 - x2| + |y1 - y2|
                  int d = abs(x1 - x2) + abs(y1 - y2);
  
                  // Add undirected edge
                  adj[i].push_back({j, d});
                  adj[j].push_back({i, d});
              }
          }
  
          // Step 2: Use Prim's Algorithm to construct Minimum Spanning Tree (MST)
          // Min-heap stores pair {weight, node}
          // Time complexity: O(E * log V) = O(n^2 * log n) for complete graph
          priority_queue<pair<int, int>, vector<pair<int , int>>, greater<>> pq; 
  
          // Start with the 0th node, edge weight 0
          pq.push({0, 0});
  
          // Track nodes included in MST
          vector<bool> inMST(n, false);
  
          int sum = 0; // Stores total minimum cost
  
          // Prim's main loop
          while (!pq.empty()) {
              auto p = pq.top();
              pq.pop();
  
              int wt = p.first;    // Current edge weight
              int node = p.second; // Current node
  
              if (inMST[node]) continue; // Skip if already added to MST
  
              inMST[node] = true;  // Mark node as included
              sum += wt;           // Add edge weight to total cost
  
              // Traverse neighbors of current node
              for (auto &temp : adj[node]) {
                  int nbr = temp.first;   // Neighbor node
                  int w = temp.second;    // Edge weight
  
                  // If neighbor not yet in MST, add to priority queue
                  if (!inMST[nbr]) {
                      pq.push({w, nbr});
                  }
              }
          }
  
          // Return total minimum cost of connecting all houses
          return sum;
      }
  };
  
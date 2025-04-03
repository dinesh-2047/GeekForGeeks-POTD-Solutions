// Undirected Graph Cycle


class Solution {
    public:
        bool checkCycle(int src, unordered_map<int, list<int>>& adj, vector<bool>& visited, int parent) {
            visited[src] = true;
            for (int neighbor : adj[src]) {
                if (neighbor == parent) continue;
                if (visited[neighbor]) return true;
                if (checkCycle(neighbor, adj, visited, src)) return true;
            }
            return false;
        }
    
        bool isCycle(int V, vector<vector<int>>& edges) {
            unordered_map<int, list<int>> adj; 
            for (auto& edge : edges) {
                int u = edge[0], v = edge[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            
            vector<bool> visited(V, false);
            for (int i = 0; i < V; i++) {
                if (!visited[i]) {
                    if (checkCycle(i, adj, visited, -1)) return true;
                }
            }
            return false;
        }
    };
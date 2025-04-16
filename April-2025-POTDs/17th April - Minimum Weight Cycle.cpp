// Minimum Weight Cycle


//using floyd warshall 
class Solution {
    public:
        int findMinCycle(int V, vector<vector<int>>& edges) {
            const int INF = 1e9;
            vector<vector<int>> dist(V, vector<int>(V, INF));
            vector<vector<int>> adj(V, vector<int>(V, INF));
    
            for (auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                if (w < adj[u][v]) {
                    adj[u][v] = w;
                    adj[v][u] = w;
                    dist[u][v] = w;
                    dist[v][u] = w;
                }
            }
    
            int min_cycle = INF;
    
            for (int k = 0; k < V; ++k) {
                for (int i = 0; i < k; ++i) {
                    for (int j = 0; j < i; ++j) {
                        if (dist[i][j] != INF && adj[i][k] != INF && adj[k][j] != INF) {
                            int cycle_weight = dist[i][j] + adj[i][k] + adj[k][j];
                            min_cycle = min(min_cycle, cycle_weight);
                        }
                    }
                }
    
                for (int i = 0; i < V; ++i) {
                    for (int j = 0; j < V; ++j) {
                        if (dist[i][k] < INF && dist[k][j] < INF) {
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                        }
                    }
                }
            }
    
            return (min_cycle == INF) ? -1 : min_cycle;
        }
    };
    
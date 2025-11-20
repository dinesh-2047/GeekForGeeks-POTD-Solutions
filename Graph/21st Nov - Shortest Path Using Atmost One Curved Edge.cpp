// Shortest Path Using Atmost One Curved Edge


class Solution {
public:
    int shortestPath(int n,  int a, int b, vector<vector<int>>& edges) {
        // Build adjacency list with both edge weights
        vector<vector<pair<int, pair<int, int>>>> adj(n + 1);
        
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w1 = edge[2], w2 = edge[3];
            adj[u].push_back({v, {w1, w2}});
            adj[v].push_back({u, {w1, w2}});
        }
        
        // State: {distance, {vertex, curved_used}}
        // curved_used: 0 = no curved edge used, 1 = curved edge used
        priority_queue<pair<int, pair<int, int>>, 
                      vector<pair<int, pair<int, int>>>, 
                      greater<pair<int, pair<int, int>>>> pq;
        
        // Distance array: dist[vertex][curved_used]
        vector<vector<int>> dist(n + 1, vector<int>(2, INT_MAX));
        
        // Start from vertex a with no curved edge used
        pq.push({0, {a, 0}});
        dist[a][0] = 0;
        
        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second.first;
            int curved_used = pq.top().second.second;
            pq.pop();
            
            if (d > dist[u][curved_used]) continue;
            
            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int straight_weight = neighbor.second.first;
                int curved_weight = neighbor.second.second;
                
                // Use straight edge
                if (dist[u][curved_used] + straight_weight < dist[v][curved_used]) {
                    dist[v][curved_used] = dist[u][curved_used] + straight_weight;
                    pq.push({dist[v][curved_used], {v, curved_used}});
                }
                
                // Use curved edge (only if we haven't used one before)
                if (curved_used == 0 && dist[u][0] + curved_weight < dist[v][1]) {
                    dist[v][1] = dist[u][0] + curved_weight;
                    pq.push({dist[v][1], {v, 1}});
                }
            }
        }
        
        // Return minimum distance to vertex b (with or without using curved edge)
        return min(dist[b][0], dist[b][1]);
    }
};
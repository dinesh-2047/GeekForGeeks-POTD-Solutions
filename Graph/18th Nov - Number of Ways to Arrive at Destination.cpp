// Number of Ways to Arrive at Destination

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long, long long>>> adj(n);

        // Build the adjacency list
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<long long, long long>,
                       vector<pair<long long, long long>>,
                       greater<pair<long long, long long>>> pq;

        vector<long long> dist(n, 1e12); // Distance array initialized to a large value
        vector<int> ways(n, 0);         // Ways array initialized to 0
        dist[0] = 0;                    // Distance to source node is 0
        ways[0] = 1;                    // There is one way to reach the source node
        int mod = (int)(1e9 + 7);

        pq.push({0, 0}); // Push the source node into the priority queue

        while (!pq.empty()) {
            auto it = pq.top();
            long long dis = it.first;
            long long node = it.second;
            pq.pop();

            // Explore all neighbors of the current node
            for (auto x : adj[node]) {
                long long adjNode = x.first;
                long long edwt = x.second;

                // If a shorter path to adjNode is found
                if (dis + edwt < dist[adjNode]) {
                    dist[adjNode] = dis + edwt;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node]; // Update the number of ways to reach adjNode
                }
                // If another shortest path to adjNode is found
                else if (dis + edwt == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod; // Return the number of ways to reach node n-1
    }
};
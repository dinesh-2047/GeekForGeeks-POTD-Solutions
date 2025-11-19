// Make Strings Equal


class Solution {
  public:
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) {
         int INF = INT_MAX;
        // Distance matrix for 26 characters
        vector<vector<int>> dist(26, vector<int>(26, INF));
        
        // dist[x][x] = 0
        for (int i = 0; i < 26; i++)
            dist[i][i] = 0;
        
        // Fill direct transformation costs
        for (int i = 0; i < transform.size(); i++) {
            int u = transform[i][0] - 'a';
            int v = transform[i][1] - 'a';
            dist[u][v] = min(dist[u][v], cost[i]);
        }
        
        // Floyd-Warshall for all-pairs minimum transform cost
        for (int k = 0; k < 26; k++)
            for (int i = 0; i < 26; i++)
                for (int j = 0; j < 26; j++)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        
        int ans = 0;
        
        // Try to match characters of both strings
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == t[i])
                continue; // already same
            
            int best = INF;
            int a = s[i] - 'a';
            int b = t[i] - 'a';
            
            // Option 1: Transform s[i] to t[i]
            best = min(best, dist[a][b]);
            
            // Option 2: Transform t[i] to s[i]
            best = min(best, dist[b][a]);
            
            // Option 3: Transform both to a common character c
            for (int c = 0; c < 26; c++) {
                if (dist[a][c] < INF && dist[b][c] < INF)
                    best = min(best, dist[a][c] + dist[b][c]);
            }
            
            if (best == INF)
                return -1;
            
            ans += best;
        }
        
        return ans;
    }
};
        

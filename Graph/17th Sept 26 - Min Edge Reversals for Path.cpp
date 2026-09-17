// Min Edge Reversals for Path


class Solution {
  public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        unordered_map<int , list<pair<int , int>>> adj; 
        
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
            
        }
        
        
        vector<int> dist(n + 1, 1e9);
        
        dist[src] = 0 ; 
        
        priority_queue<pair<int , int>, vector<pair<int , int>>, greater<>> pq; 
        pq.push({src, 0});
         vector<bool> visited(n + 1, false);
        
        while(!pq.empty()){
            int curr = pq.top().first; 
            int cost = pq.top().second; 
            pq.pop();
            
            
            for(auto &[nbr, c] : adj[curr]){
                if(!visited[nbr] && c + cost < dist[nbr]){
                    dist[nbr] = c +  cost; 
                    pq.push({nbr, dist[nbr]});
                }
            }
            
            
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
        
    }
};
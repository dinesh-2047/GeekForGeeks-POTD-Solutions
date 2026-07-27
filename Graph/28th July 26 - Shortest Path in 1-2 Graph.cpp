// Shortest Path in 1-2 Graph

class Solution {
  public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        unordered_map<int , list<pair<int , int>>> adj; 
        
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u , w});
            
        }
        
        
        priority_queue<pair<int , int>, vector<pair<int ,int>>, greater<>>pq; 
        pq.push({0, src});
        vector<int> dist(V, INT_MAX);
        dist[src] = 0 ; 
        
        while(!pq.empty()){
            auto [wt, node] = pq.top();
            pq.pop();
            
            if(node == dest) return wt; 
            
            for(auto &[nbr, w] : adj[node]){
                if(w + wt < dist[nbr]){
                    dist[nbr] = w + wt; 
                    pq.push({dist[nbr], nbr});
                }
            }
        }
        return -1; 
        
    }
};
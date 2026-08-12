// Longest Path in a Directed Acyclic Graph

class Solution {
  public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
       unordered_map<int  , list<pair<int , int>>> adj; 
       for(auto &edge :edges){
           int u = edge[0];
           int v = edge[1];
           int w = edge[2];
           
           adj[u].push_back({v, w});
       }
       
       vector<int> dist(V, INT_MIN);
       
       priority_queue<pair<int , int>> pq; 
       pq.push({0, src});
       dist[src] = 0 ; 
       while(!pq.empty()){
           auto [w, node] = pq.top();
           pq.pop();
           
           for(auto &[nbr, wt] : adj[node] ){
               if(w+wt > dist[nbr]){
                   dist[nbr] = w + wt; 
                   pq.push({dist[nbr], nbr});
               }
           }
       }
       return dist ;
    }
};
// Number of Ways to Arrive at Destination

class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
         unordered_map<int, list<pair<int , int>>>adj; 
        
       for(auto &edge : edges){
          int u = edge[0];
          int v = edge[1];
          int t = edge[2];
          
          adj[u].push_back({v, t});
          adj[v].push_back({u, t});
       }
       
       
       priority_queue<pair<int , int>, vector<pair<int , int>>, greater<>>pq;
       pq.push({0, 0});
       
       vector<int>dist(V, 1e9);
       dist[0] = 0 ;
       int ways = 0 ;
       int min_t = INT_MAX; 
       
       while(!pq.empty()){
           auto [t, node] = pq.top();
           pq.pop();

           if(node == V - 1){
               if(t < min_t){
                   min_t = t; 
                   ways = 1; 
               }
               else if(t == min_t){
                   ways++;
               }
              
           }
           
           for(auto &nbr : adj[node]){
               int timee = nbr.second; 
               int ngbr = nbr.first; 
               
               if(t + timee <= dist[ngbr] ){
                  dist[ngbr] = t + timee; 
                  pq.push({dist[ngbr], ngbr});
               } 
           }
       }
      
      return ways; 
        
    }
};
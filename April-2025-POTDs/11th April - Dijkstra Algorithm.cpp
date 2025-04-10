// Dijkstra Algorithm


// Approach 1 or code using priority queue 
class Solution {
    public:
      vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
         unordered_map<int ,list<pair<int , int>>>adj; 
         
         for(auto &edge : edges){
             int u = edge[0];
             int v = edge[1];
             int w = edge[2];
             
             adj[u].push_back({v,w});
             adj[v].push_back({u,w});
         }
         
         priority_queue<pair<int, int>, vector<pair<int , int>>, greater<>>pq; 
         vector<int>ans(V, INT_MAX);
         ans[src]  = 0;
         pq.push({0,src});
         
         while(!pq.empty()){
             auto curr = pq.top();
             pq.pop();
             
             int currdist = curr.first; 
             int node = curr.second; 
             
             for(auto &temp : adj[node]){
                 int nbr = temp.first; 
                 int dist = temp.second; 
                 
                 if(currdist + dist < ans[nbr]){
                     ans[nbr] = currdist + dist; 
                     pq.push({currdist+ dist, nbr});
                 }
             }
         }
         return ans; 
          
      }
  };
  
// Minimum height roots

class Solution {
  public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        if(V == 1) return {0} ;
       vector<int>result; 
       
       vector<int>inDegree(V, 0);
       unordered_map<int , list<int>>adj; 
       
       for(auto &edge : edges){
           int u = edge[0];
           int v = edge[1];
           
           adj[u].push_back(v);
           adj[v].push_back(u);
           inDegree[u]++;
           inDegree[v]++;
       }
       
       
       queue<int>q; 
       
       for(int i = 0; i < V; i++){
           if(inDegree[i] == 1) q.push(i);
       }
       
       
       
       int left = V; 
       
       while(left > 2){
           int n = q.size();
           left -= n;  
           
           while(n--){
               int curr = q.front();
               q.pop();
               
               for(auto &nbr : adj[curr]){
                   inDegree[nbr]--;
                   if(inDegree[nbr] == 1){
                       q.push(nbr);
                   }
               }
              
               
           }
       }
       while(!q.empty()){
          result.push_back(q.front());
          q.pop();
       }
       return result; 
        
    }
};
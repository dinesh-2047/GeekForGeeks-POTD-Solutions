// Party in Town

class Solution {
  public:
  int n ;
  pair<int , int> bfs(vector<vector<int>> &adj, int st){
      vector<int> dist(n, -1);
      queue<int> q; 
      
      dist[st] = 0; 
      q.push(st);
      
      int fn = st; 
      int fd = 0 ; 
      
      while(!q.empty()){
          auto curr = q.front();
          q.pop();
          
          for(auto nbr :adj[curr]){
              nbr--; 
              
              if(dist[nbr] == -1){
                  dist[nbr] = dist[curr] + 1; 
                  q.push(nbr);
                  
                  if(dist[nbr] > fd){
                      fd = dist[nbr];
                      fn = nbr; 
                  }
              }
          }
      }
      return {fn , fd}; 
  }
  
    int partyHouse(vector<vector<int>> &adj) {
        n = adj.size();
        
        pair<int , int> f = bfs(adj, 0);
        int dend  = f.first; 
        pair<int , int> sec = bfs(adj, dend);
        int d = sec.second; 
        
        return (d + 1)/2;
    }
};
// Topological Sort 

class Solution {
    public:
      vector<int> topoSort(int V, vector<vector<int>>& edges) {
          
          unordered_map<int , list<int>>adj; 
           vector<int>indegree(V, 0);
          for(auto &edge : edges){
              int u = edge[0];
              int v = edge[1];
              
              adj[u].push_back(v);
              indegree[v]++;
          }
          
          queue<int>q; 
          for(int i = 0 ; i<V; i++){
              if(indegree[i]==0) q.push(i);
          }
          vector<int>ans;
          while(!q.empty()){
              auto curr = q.front();
              q.pop();
              ans.push_back(curr);
              
              for(auto &nbr : adj[curr]){
                  indegree[nbr]--;
                  if(indegree[nbr]==0){
                      q.push(nbr);
                  }
              }
          }
          return ans; 
      }
  };
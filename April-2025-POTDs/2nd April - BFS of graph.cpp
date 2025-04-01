// BFS of graph 


class Solution {
    public:
      // Function to return Breadth First Traversal of given graph.
      vector<int> bfs(vector<vector<int>> &adj) {
         int n = adj.size();
         
         queue<int>q; 
         q.push(0);
         vector<int>ans;
        
         vector<bool>visited(n+1, false);
          visited[0] = true; 
         
         while(!q.empty()){
             auto curr = q.front();
             q.pop();
             ans.push_back(curr);
             for(auto &nbr : adj[curr]){
                 if(!visited[nbr]){
                     q.push(nbr);
                     visited[nbr] = true; 
                 }
             }
         }
          return ans; 
      }
  };
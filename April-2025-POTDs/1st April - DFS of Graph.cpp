// DFS on Graph 


class Solution {
    public:
    void dfs(vector<vector<int>>&adj , vector<bool>&visited, int node , vector<int> &ans){
        visited[node] = true; 
        ans.push_back(node);
        
        for(auto &nbr : adj[node]){
            if(!visited[nbr]){
                dfs(adj , visited, nbr, ans);
            }
            
        }
    }
    
      vector<int> dfs(vector<vector<int>>& adj) {
          vector<int>ans;
          int n = adj.size();
          
          vector<bool>visited(n,false);
          
          for(int i = 0 ; i<n; i++ ){
              if(!visited[i]){
                  dfs(adj , visited, i, ans );
              }
          }
          return ans; 
      }
  };
  
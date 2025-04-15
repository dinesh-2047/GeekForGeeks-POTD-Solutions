// Floyd Warshall


class Solution {
    public:
      void floydWarshall(vector<vector<int>> &dist) {
         int n = dist.size();
         
         for(int via = 0 ; via<n; via++){
             for(int i = 0 ; i<n; i++){
                 for(int j = 0 ; j<n; j++){
                     dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                 }
             }
         }
         
      }
  };
// 1s Surrounded by 0s


class Solution {
  public:
  int n , m; 
  vector<vector<int>> directions = {{0,1}, {1,0},{0,-1},{-1,0}};
  void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i , int j){
      
      visited[i][j] = true; 
      
      for(auto &dir : directions){
          int newi = i + dir[0];
          int newj = j + dir[1];
          
          if(newi  < m && newi >= 0 && newj < n && newj >= 0 && !visited[newi][newj] && grid[newi][newj] == 1)
           dfs(grid, visited, newi, newj) ;
          
      }
        
      
  }
  
    int cntOnes(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int result = 0 ; 
          vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0 ; i  < m; i++){
            for(int j = 0 ; j  < n; j++ ){
                if(i == 0 || i == m -1 || j == 0 || j == n- 1){
                if(grid[i][j] == 1){
                    dfs(grid,visited, i, j);
                }
                }
            }
            }
        
        
        for(int i = 1 ;i  < m; i++){
            for(int j = 1; j< n; j++){
                if(grid[i][j] == 1 && !visited[i][j]) result++;
            }
        }
        return result; 
        
    }
};
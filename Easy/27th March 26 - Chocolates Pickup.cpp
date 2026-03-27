// Chocolates Pickup

class Solution {
  public:
  int m , n ;
  vector<int>moves = {-1, 0, 1};
  vector<vector<vector<int>>> dp; 
  int solve(vector<vector<int>> &grid, int i , int j1 , int j2){
      if(j1 < 0 || j1 >= n || j2 < 0 || j2 >= n ) return -1e9 ; 
      
       if(dp[i][j1][j2] != -1 ) return dp[i][j1][j2];
      
      int curr = grid[i][j1];
      if(j1 != j2) curr += grid[i][j2];
      
      if( i == m - 1)  return curr; 
      
      int result = -1e9; 
      
      for(int r = 0 ; r < moves.size(); r++){
          for(int j = 0 ; j < moves.size(); j++){
              result = max(result, solve(grid, i + 1, j1 +moves[r], j2 + moves[j]));
          }
      }
      
      return dp[i][j1][j2] = result + curr; 
      
  }
  
    int maxChocolate(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        dp.assign(m , vector<vector<int>> (n , vector<int>(n, -1)));
        
        return solve(grid, 0, 0, n - 1) ; 
        
    }
};
// Adventure in a Maze
class Solution {
  public:
  int n ;
  int mod = 1e9+ 7; 
  int dp1[101][101]; 
  int dp2[101][101][598];
 
  int solve1(vector<vector<int>> &grid, int i , int j){
      if(i >= n || j >= n  ) return 0 ; 
      if(i == n - 1 && j == n- 1) return 1; 
      if(dp1[i][j]!=-1) return dp1[i][j];
      int result = 0 ; 
      if(grid[i][j] == 1){
          result = (result +  solve1(grid, i, j + 1))%mod;
      }
      else if(grid[i][j] == 2){
          result = (result +  solve1(grid, i + 1, j))%mod;
      }
      else {
          result = (result +  solve1(grid, i, j + 1))%mod;
          result = (result + solve1(grid, i + 1, j))%mod;
      }
      return dp1[i][j] =  result%mod; 
  }
  
  
  int solve2(vector<vector<int>> &grid, int i , int j, int sum ){
       if(i >= n || j >= n  ) return 0 ; 
      if(i == n - 1 && j == n- 1){
          sum += grid[i][j];
          return sum; 
      }
      
      if(dp2[i][j][sum]!=-1) return dp2[i][j][sum];
     
      
      int result = 0; 
      if(grid[i][j] == 1){
          result =  max(result, solve2(grid, i, j + 1, sum + grid[i][j]));
      }
      else  if(grid[i][j] == 2){
          result =  max(result, solve2(grid, i + 1, j, sum + grid[i][j]));
      }
      else {
          result = max(result, solve2(grid, i , j + 1, sum + grid[i][j]));
          result = max(result, solve2(grid, i + 1, j , sum + grid[i][j]));
      }
      
      return dp2[i][j][sum] =  result; 
      
      
  }
    vector<int> findWays(vector<vector<int>>& grid) {
        n = grid.size();
        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));
        int totalPaths = solve1(grid, 0 , 0)%mod;
        int maxAdv = solve2(grid, 0 , 0 , 0);
        return {totalPaths, maxAdv};
    }
};
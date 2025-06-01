// Unique Paths in a Grid




// Rec + memo 

class Solution {
  public:
  int m ; 
  int n ; 
 
  int solve(int i , int j , vector<vector<int>> &grid, vector<vector<int>> &dp){
     if(i>=m||j >= n || grid[i][j] == 1 ) return 0; 
     
     if(i==m-1 && j==n-1 ) return 1; 
      
      if(dp[i][j]!=-1) return dp[i][j];
      
      int right = solve(i, j+1, grid,dp );
      int down = solve(i+1, j , grid,dp);
      
      return dp[i][j] = down  + right; 
  }
  
    int uniquePaths(vector<vector<int>> &grid) {
       m = grid.size();
       n = grid[0].size();
      
      if(grid[0][0]==1 && grid[m-1][n-1] == 0 ) return 0 ; 
      
     vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
     return solve(0,0, grid,dp);
    
        
    }
};









//Tabulation 

class Solution {
  public:
  int m ; 
  int n ; 
    int uniquePaths(vector<vector<int>> &grid) {
       m = grid.size();
       n = grid[0].size();
       if(grid[0][0]==1||grid[m-1][n-1]==1) return 0; 
       
       vector<vector<int>> dp(m,vector<int>(n, 0));
       dp[0][0] = 1;
       for(int col = 1 ; col <n ; col++){
           if(col-1 >=0 && grid[0][col-1]==1){
               dp[0][col]=0;
               grid[0][col] =1; 
           } 
           
          else if(grid[0][col]==1) dp[0][col] = 0 ;
           
           else dp[0][col]=1; 
       }
       
       for(int row = 1 ; row < m ;row++){
           if(row-1>=0 && grid[row-1][0]==1  ) {
               dp[row][0] = 0;
               grid[row][0] = 1; 
           }
          else if(grid[row][0] == 1) dp[row][0] = 0;
           else dp[row][0] = 1; 
       }
       
       
       for(int i= 1; i <m; i++){
           for(int j = 1; j <n; j++){
      
            if(grid[i][j]==1) dp[i][j] = 0 ;
               else dp[i][j] = dp[i-1][j] + dp[i][j-1];
           }
       }
       return dp[m-1][n-1];
        
    }
};













// SO 
class Solution {
  public:
  int m ; 
  int n ; 
    int uniquePaths(vector<vector<int>> &grid) {
       m = grid.size();
       n = grid[0].size();
       if(grid[0][0]==1||grid[m-1][n-1]==1) return 0; 
       
       vector<int>curr(n , 0 );
       vector<int>prev(n , 0 ); 
       curr[0] = 1;
       for(int col = 1 ; col <n ; col++){
           if(col-1 >=0 && grid[0][col-1]==1){
               curr[col]=0;
               grid[0][col] =1; 
           } 
           
          else if(grid[0][col]==1) curr[col] = 0 ;
           
           else curr[col]=1; 
       }
 
       
       prev = curr; 
       for(int i= 1; i <m; i++){
            if (grid[i][0] == 1) curr[0] = 0;
            else curr[0] = prev[0];
           for(int j = 1; j <n; j++){
               if(grid[i][j]==1) curr[j] = 0 ;
               else curr[j] = prev[j] + curr[j-1];
           }
           prev= curr;
       }
       return prev[n-1];
        
    }
};
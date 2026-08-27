// Minimum Cost Selection

class Solution {
  public:
  int n ; 
  int dp[100001][4];
  int solve(vector<vector<int>> &mat, int i, int prev){
      if(i >= n ){
          return 0; 
      }
      if(dp[i][prev + 1]!=-1) return dp[i][prev+1];
      int result = 1e9; 
      for(int j = 0; j  < 3 ; j++){
          if(prev == j ) continue; 
          result = min(result, mat[i][j] + solve(mat, i + 1, j));
      }
      return dp[i][prev + 1] =  result; 
  }
    int minCost(vector<vector<int>>& mat) {
       n = mat.size();
       memset(dp, -1, sizeof(dp));
       return solve(mat, 0,-1);
        
    }
};
// Largest Zigzag Sequence

class Solution {
  public:
  int n ; 
  vector<vector<int>> dp; 
  int solve(vector<vector<int>> &mat, int i , int j ){
      if(i == n - 1) return mat[i][j];
      if(dp[i][j]!=-1) return dp[i][j];
      int maxi = 0 ; 
      for(int k = 0 ; k  < n; k++){
          if(k!=j) maxi = max(maxi, solve(mat, i + 1, k ));
      }
      return dp[i][j] =  mat[i][j] + maxi; 
  }
    int zigzagSequence(vector<vector<int>>& mat) {
        n = mat.size();
        dp.resize(n + 1, vector<int>(n + 1, -1));
        int result = 0 ;
        for(int i = 0 ; i < n; i++){
            result  = max(result, solve(mat, 0, i));
        }
        return result; 
        
    }
};
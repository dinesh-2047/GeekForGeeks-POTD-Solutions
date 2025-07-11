// Gold Mine Problem


// Approach 1 rec + memo 
class Solution {
  public:
   int n ; 
   int m ; 
  int solve(vector<vector<int>>& mat , int i , int j , vector<vector<int>> &dp){
      if(i>=m || j>= n || i < 0 || j < 0 ) return 0; 
      
      if(dp[i][j]!=-1) return dp[i][j];
      
      int op1 = mat[i][j] + solve(mat , i, j+1, dp);
      int op2 = mat[i][j] + solve(mat , i-1, j+1, dp);
      int op3 = mat[i][j] + solve(mat ,i+1, j + 1, dp);
      return dp[i][j] =  max({op1, op2 , op3});
  }
  
    int maxGold(vector<vector<int>>& mat) {
          m = mat.size();
          n = mat[0].size();
         int result = 0 ; 
         vector<vector<int>> dp(m + 1, vector<int>(n+1, -1));
          for(int i = 0 ; i < m; i++){
              result = max(result , solve(mat , i , 0, dp));
          }
          
          return result; 
    }
};








//Approach 2 Tabulation 
class Solution {
public:
    int maxGold(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Step 1: Fill the last column as base case
        for (int i = 0; i < m; i++) {
            dp[i][n - 1] = mat[i][n - 1];
        }

        // Step 2: Fill remaining columns from right to left
        for (int j = n - 2; j >= 0; j--) {
            for (int i = 0; i < m; i++) {
                int right = dp[i][j + 1];
                int rightUp = (i - 1 >= 0) ? dp[i - 1][j + 1] : 0;
                int rightDown = (i + 1 < m) ? dp[i + 1][j + 1] : 0;

                dp[i][j] = mat[i][j] + max({right, rightUp, rightDown});
            }
        }

        // Step 3: Get the max from the first column
        int result = 0;
        for (int i = 0; i < m; i++) {
            result = max(result, dp[i][0]);
        }

        return result;
    }
};
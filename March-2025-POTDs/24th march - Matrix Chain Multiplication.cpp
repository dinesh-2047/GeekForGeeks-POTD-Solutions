// Matrix Chain Multiplication

// rec + memo 

class Solution {
    public:
    int n ;
    int solve(vector<int> &arr, int i , int j, vector<vector<int>> &dp ){
        if(i==j) return 0; 
        
        int mini = 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        
        for(int k = i ; k<j; k++){
            int steps = arr[i-1] * arr[k] * arr[j] + solve(arr, i, k,dp ) + solve(arr, k+1, j,dp);
            mini = min(mini , steps);
        }
        return dp[i][j] =  mini ;
    }
    
      int matrixMultiplication(vector<int> &arr) {
          n = arr.size();
          vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
          return solve(arr, 1, n-1,dp);
          
      }
  };





// tabulation /
class Solution {
  public:
  int n ;
  
  
    int matrixMultiplication(vector<int> &arr) {
        n = arr.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
     
        int mini = 1e9;
        for(int i = n-1; i>=1 ;i--){
            for(int j = i+1 ; j<n; j++){
                 int mini = 1e9;

                  for(int k = i ; k<j; k++){
                      int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                      mini = min(mini , steps);
                  }
                  dp[i][j] =  mini ;
              
            }
        }
       return dp[1][n-1]; 
    }
};
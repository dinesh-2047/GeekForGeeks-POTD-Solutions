// Get Minimum Squares


class Solution {
  public:
  vector<int>dp ; 
  int solve( int sum , int &n ){
      if(sum == n){
          return 0 ; 
      }
      if(sum > n ){
          return 1e9;
      }
      
      if(dp[sum] != - 1) return dp[sum];
      
      int result = 1e9;
      
      for(int j = 1 ; j * j  <= n; j++){
          int c = 1 + solve( sum + (j * j), n);
          result = min(result , c);
      }
      return dp[sum] =  result; 
      
  }
  
    int minSquares(int n) {
        dp.assign(n + 1, -1);
        return solve(0, n );
        
    }
};
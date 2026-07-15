// Numbers with Given Digit Sum

class Solution {
  public:
  int dp[10][82];
  int solve(int n , int sum){
      if(n == 0 && sum == 0 ) {
          return 1; 
      }
      
      if(sum == 0 && n > 0 ) return 0 ;
      
      if(n < 0 || sum < 0 ) return 0; 
      
      if(dp[n][sum] != -1 ) return dp[n][sum];
      
      int result =0;
      for(int i = n==1?1:0; i <= 9; i++){
          result = result + solve(n -1, sum  - i);
      }
      return dp[n][sum] =  result;
  }
    int countWays(int n, int sum) {
        memset(dp, -1, sizeof(dp));
       int result = solve(n , sum);
       return result == 0 ? -1 : result; 
       
        
    }
};
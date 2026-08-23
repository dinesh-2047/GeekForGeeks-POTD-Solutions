// Count Prefix-Balanced Binary Strings


class Solution {
  public:
  int mod = 1e9 + 7; 
  int dp[1001][1001];
  int solve(int n , int m){
      if(n == 0 && m == 0 ) return 1; 
      if(dp[n][m]!=-1) return dp[n][m];
      int result = 0;
      if(m > n ){
          result  = (result +  solve(n, m -1))%mod;
      }
      if(n > 0){
          result  = (result + solve(n -1, m))%mod;
      }
      
      return dp[n][m] = result;
  }
    int prefixStrings(int n) {
       memset(dp, -1, sizeof(dp));
      return solve(n , n);
        
    }
};
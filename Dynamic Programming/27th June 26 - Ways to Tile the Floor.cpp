// Ways to Tile the Floor

class Solution {
  public:
  vector<int> dp; 
  int mod = 1e9 + 7 ; 
  int solve(int n , int m ){
      if(n == 1) return 1; 
      if(n == m) return 2; 
      
      if(n <= 0 ) return 0 ;
      
      if(dp[n]!=-1) return dp[n];
      
      
      int op1 = solve(n - 1, m );
      int op2 = 0 ; 
      if(n >=m ){
          op2 = solve(n - m , m );
      }
      return dp[n] = (op1 + op2)%mod; 
  }
    int countWays(int n, int m) {
        dp.assign(n + 1, -1);
        return solve(n, m);
    }
};
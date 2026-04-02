// Painting the Fence


class Solution {
  public:
  vector<int>dp; 
  int solve(int n,int k ){
      if(n == 1) return k ;
      if(n == 2) return k * k ;
      
      if(dp[n] != -1 ) return dp[n];
      
      int op1 = solve(n -1, k) * (k - 1);
      int op2 = solve(n - 2, k) * (k - 1);
      
      return dp[n] = op1 + op2; 
      
      
  }
  
    int countWays(int n, int k) {
        dp.assign(n+1, -1);
       return solve(n , k);
    }
};
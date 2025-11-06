// Ways To Tile A Floor



// Approach 1 rec + memo 
class Solution {
  public:
  vector<int>dp ; 
  int solve(int n ){
   if(n <= 2) return n; 
      if(dp[n]!=-1) return dp[n];
      return dp[n] =  solve(n-1) + solve(n-2);
  }
    int numberOfWays(int n) {
        dp.assign(n + 1, -1);
       return solve(n);
        
    }
};





//Approach 2 bottom up 
class Solution {
  public:
    int numberOfWays(int n) {
        vector<int>dp(n+1, 0);
        
        dp[0] = dp[1] = 1; 
        for(int i = 1; i  <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
        
    }
};
// Minimum Cost for n Characters

class Solution {
  public:
  vector<int> dp; 
  int solve(int n , int &i , int &d, int &c){
      if(n == 1) return i ; 
      
      if(n < 0 ){
           return 1e9; 
      }
      if(dp[n]!=-1) return dp[n];
      
      int result = 1e9; 
      if(n%2 == 0 ){
          result = min(result, i + solve(n-1, i, d, c));
          result = min(result, c + solve(n/2, i , d , c));
      }
      
      else {
          result = min(result, i + solve(n-1, i , d, c));
          result = min(result, c + i + solve(n/2, i , d, c));
          result = min(result, c + d + solve((n + 1)/2, i, d, c));
      }
      return dp[n] = result; 
  }
    int minCost(int n, int i, int d, int c) {
       dp.resize(n + 1, -1);
       return solve(n, i , d, c);
        
    }
};

// Cut rope to maximise product


class Solution {
  public:
  vector<vector<int>> dp; 
  int solve(int n , int cut, int sum){
      if(cut < 0 || sum > n ) return 0; 
      if(cut == 0 ){
          if(sum == n)
          return 1; 
          return 0;
      }
      if(dp[cut][sum] !=-1) return dp[cut][sum];
      int result = 0; 
      for(int i = 1; i < n; i++){
          result = max(result, i * solve(n , cut-1, sum + i ));
      }
      return dp[cut][sum] = result; 
      
  }
    int maxProduct(int n) {
         int result = 0 ; 
         for(int cut = 1; cut <= n; cut++){
             dp.assign(n+1, vector<int>(n + 1, -1));
             result = max(result, solve(n , cut,0));
         }
         return result; 
         
    }
};
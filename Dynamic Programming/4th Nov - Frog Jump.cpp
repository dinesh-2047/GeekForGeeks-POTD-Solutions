// Frog Jump


class Solution {
  public:
  int n ;
  vector<int>dp ; 
  int solve(int i, vector<int>& height){
      if( i == n -1 ) return 0 ; 
      if(i >= n ) return 1e9; 
      if(dp[i]!=-1) return dp[i];
      int result = 1e9 ; 
      for(int j = i + 1; j <= i + 2; j++){
          if(j <n ){
              int c = abs(height[j] - height[i]) + solve(j, height);
              result = min(result , c);
          }
          
      }
      return dp[i] = result ;
  }
  
  
    int minCost(vector<int>& height) {
         n = height.size();
        dp.assign(n + 1, -1);
        
        for()
        
        return solve(0, height);
        
    }
};
// Optimal Strategy For A Game

class Solution {
  public:
  int n ;
  vector<vector<int>>dp; 
  int solve(vector<int> &arr, int i , int j ){
      if(i > j ) return 0;
      
       if(dp[i][j]!=-1) return dp[i][j];
      
      int take_first = arr[i] + min( solve(arr, i + 2, j), solve(arr, i + 1, j-1));
      int take_last = arr[j] +  min(solve(arr, i , j - 2), solve(arr, i + 1, j - 1));
      
      return dp[i][j] =  max(take_first , take_last);
  }
  
  
    int maximumAmount(vector<int> &arr) {
         n = arr.size();
         dp.assign(n + 1, vector<int>(n + 1, -1));
        return solve(arr, 0 , n-1);
        
        
        
    }
};
// Minimum Elements Outside Subsequences

class Solution {
  public:
  int n; 
  vector<vector<vector<int>>> dp;
  int solve(vector<int> &arr, int i , int inc, int dec){
      if(i >= n ) return 0 ; 
      
      if(dp[i][inc+1][dec+1]!=-1) return dp[i][inc+1][dec+1];
      
      int result = 0 ; 
      result = solve(arr, i + 1, inc, dec);
      if(inc == -1 || arr[i] > arr[inc]){
          result = max(result, 1 + solve(arr, i + 1, i , dec) );
      }
      
      if(dec == -1 || arr[i] < arr[dec]){
          result = max(result, 1 + solve(arr, i + 1, inc, i));
      }
      return dp[i][inc+1][dec+1] =  result; 
  }
    int minCount(vector<int>& arr) {
        n = arr.size();
         dp.resize(n+1, vector<vector<int>>(n+1, vector<int>(n+1 , -1)));
        int maxSelected = solve(arr, 0, -1, -1);
        
        return n - maxSelected; 
        
    }
};
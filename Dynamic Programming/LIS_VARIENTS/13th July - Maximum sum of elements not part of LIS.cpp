// Maximum sum of elements not part of LIS


class Solution {
  public:
  int n ; 
 
//   pair<int , int> = {sum, length}
  
  pair<int , int> solve(int i , int prev, vector<int> &arr, vector<vector<pair<int ,int>>>&dp){
      if(i>=n ) return {0, 0}; 
      
       if(dp[i][prev+1]!= pair<int , int>({-1, -1})) return dp[i][prev+1];
      
      pair<int , int> not_take = solve(i + 1, prev, arr, dp);
      
      pair<int, int> take = {0, 0};
      if(prev == -1 || arr[prev] < arr[i] ){
         
          take = solve(i + 1, i, arr, dp);
           take.first += arr[i];
          take.second += 1; 
      }
      if(take.second > not_take.second){
          return dp[i][prev+1]=  take; 
      }
      else return dp[i][prev+1]= not_take; 
  }
 
    int nonLisMaxSum(vector<int>& arr) {
        n = arr.size();
        
        int cumSum = accumulate(begin(arr), end(arr), 0);
        vector<vector<pair<int ,int>>>dp(n+1, vector<pair<int, int>>(n+1, {-1, -1}));
        pair<int , int>p = solve(0 , -1 , arr,dp);
      
        
        return cumSum - p.first ; 
        
    }
};
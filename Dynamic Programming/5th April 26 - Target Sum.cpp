// Target Sum

class Solution {
  public:
  int n; 
  map<pair<int ,int>, int>dp ; 
  int solve(vector<int> &arr, int &target, int i , int sum){
      if(i >= n){
          if(sum == target) return 1; 
          else return 0 ; 
      }
      
      pair<int , int>key = {i, sum}; 
      if(dp.count(key)) return dp[key];
      
      int op1 = solve(arr, target , i + 1, sum + arr[i]);
      int op2 = solve(arr, target, i + 1, sum - arr[i]);
      
      return dp[key] = op1 + op2; 
  }
  
    int totalWays(vector<int>& arr, int target) {
         n = arr.size();
        return solve(arr, target, 0 , 0);
        
    }
};
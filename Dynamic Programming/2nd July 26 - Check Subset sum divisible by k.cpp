// Check Subset sum divisible by k

class Solution {
  public:
  int n; 
 int dp[1001][1001][2]; 
  bool solve(vector<int> &arr, int k , int i , int sum, int addDone){
       
      if(i >= n ) {
         if(sum == 0 && addDone ) return true;
         return false; 
      }
      
      if(dp[i][sum][addDone] !=-1) return dp[i][sum][addDone];
      
      bool take = solve(arr, k , i + 1, (sum + arr[i])%k, 1);
      bool not_take = solve(arr, k , i + 1, sum, 0);
      return dp[i][sum][addDone] = take or not_take; 
      
  }
    bool divisibleByK(vector<int>& arr, int k) {
        n = arr.size();
       memset(dp, -1, sizeof(dp));
        return solve(arr, k , 0, 0, 0);
        
    }
};
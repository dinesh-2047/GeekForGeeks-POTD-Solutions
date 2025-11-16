// Max Sum Increasing Subsequence



//Approach 1 rec + memo 
class Solution {
  public:
  int n;  
  vector<vector<int>>dp ; 
  int solve(int i , vector<int> &arr, int prev){
      if(i >= n  ){
          return 0 ; 
      }
      
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
      
      
      int take  =0 ; 
      if(prev == -1 || arr[i] > arr[prev]){
          take = arr[i] + solve(i + 1 , arr, i);
      }
      int not_take  = solve(i + 1, arr, prev);
      
      return dp[i][prev+1]=  max(take, not_take);
      
  }
  
    int maxSumIS(vector<int>& arr) {
        n = arr.size();
        
       dp.assign(n +1 ,vector<int>(n + 1,-1));
        
        return solve(0 , arr, -1);
        
    }
};





//Approach 2 : tabulation
class Solution {
  public:
  int n;  
  
    int maxSumIS(vector<int>& arr) {
        n = arr.size();
        
     vector<int>dp(n , 0 );
     int result = arr[0] ; 
     
     dp[0] = arr[0];
     for(int i = 1; i  < n; i++){
         dp[i] = arr[i];
         for(int j = i -1 ; j >= 0 ; j--){
             if(arr[j] < arr[i]){
                 dp[i] = max(dp[j]+arr[i], dp[i]);
             }
         }
         result = max(dp[i], result);
     }
     return result; 
        
    }
};
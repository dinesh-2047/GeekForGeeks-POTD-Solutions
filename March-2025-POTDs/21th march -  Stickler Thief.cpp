// Stickler Thief

// Rec + memo 
class Solution {
    public:
    int n ;
    int solve(vector<int> &arr, int i, vector<int> &dp ){
        if(i>=n) return 0 ; 
        
        if(dp[i] != -1) return dp[i];
        
        int take = arr[i]  + solve(arr, i + 2,dp);
        int not_take = solve(arr, i +  1,dp);
        
        return dp[i] =  max(take, not_take);
    }
    
      int findMaxSum(vector<int>& arr) {
          n = arr.size();
          vector<int>dp(n+1, -1);
           return solve(arr, 0,dp );
          
      }
  };

// Tabulation 
  class Solution {
    public:
    int n ;
    
    
      int findMaxSum(vector<int>& arr) {
          n = arr.size();
          vector<int>dp(n+2, 0); // n+2 because we are accessing i + 2
          
          
             
           for(int i = n-1; i>=0; i--){
              
               dp[i] = max(arr[i]+dp[i+2], dp[i+1]);
               
           }
           
           return dp[0];
          
      }
  };


// space optimization /
  
class Solution {
    public:
    int n ;
    
    
      int findMaxSum(vector<int>& arr) {
          n = arr.size();
          vector<int>dp(n+2, 0);
          int curr = 0 ; 
          int next = 0 ; 
          int second_next = 0 ; 
          
             
           for(int i = n-1; i>=0; i--){
              
               curr = max(arr[i]+second_next, next);
               
               second_next = next; 
               next = curr; 
               
           }
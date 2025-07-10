// Trail of ones

// Approach 1 simple recursion by using fibonnaci sequence 
class Solution {
  public:
  
  
  int solve(int n ){
      if(n==0){
          return 1;
      }
      if(n==1) return 2; 
      
      return solve(n-1) + solve(n-2);
  }
  
    int countConsec(int n) {
        
        int totalStrings = pow(2, n);
        int invalidStrings = solve(n);
        
        return totalStrings - invalidStrings ; 
        
    }
};











//Approach2 rec + memo 
class Solution{
    public:

  int solve(int n, vector<int> &dp ){
      if(n==0){
          return 1;
      }
      if(n==1) return 2; 
      if(dp[n]!=-1) return dp[n];
      
      return dp[n] = solve(n-1,dp) + solve(n-2, dp);
  }
  
    int countConsec(int n) {
        
        int totalStrings = pow(2, n);
         vector<int>dp(n+1,-1);
        int invalidStrings = solve(n, dp);
        
       
        
        return totalStrings - invalidStrings ; 
        
    }
};










// Approach 3 bottom up 

class Solution {
  public:
  

  
    int countConsec(int n) {
        
        int totalStrings = pow(2, n);
         vector<int>dp(n+1,0);
         dp[0] = 1; 
         dp[1] = 2; 
       
        
       for(int i = 2; i <=n ;i++){
           dp[i] = dp[i-1] + dp[i-2];
           
           }
        
        return totalStrings - dp[n] ; 
        
    }
};









//Approach 4 space optimization 
class Solution {
  public:
  

  
    int countConsec(int n) {
        
        int totalStrings = pow(2, n);
        
        int  prev2  = 1; 
        int prev1= 2; 
        
       
        
       for(int i = 2; i <=n ;i++){
            int curr = prev1 + prev2;
           prev2 = prev1;
           prev1 = curr; 
           
           
           }
        
        return totalStrings - prev1 ; 
        
    }
};
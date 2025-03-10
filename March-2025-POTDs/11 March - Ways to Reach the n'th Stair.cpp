// Ways to Reach the n'th Stair

// Approach 1 - Recursion 
class Solution {
    public:
      int countWays(int n) {
          if(n==0) return 1 ;
          if(n==1) return 1; 
          return countWays(n-1) + countWays(n-2);
          
      }
  };
  

// Approach 2 - Rec + Memo
class Solution {
    public:
    int solve(int n, vector<int> &dp){
        if(n==0 || n==1) return 1; 
        if(dp[n]!=-1) return dp[n];
        return dp[n]= solve(n-1,dp) + solve(n-2,dp);
    }
    
      int countWays(int n) {
          vector<int>dp(n+1,-1);
        return solve(n,dp);
          
      }
  };


// Approach 3 - Tabulation 
class Solution {
    public:
  
      int countWays(int n) {
          vector<int>dp(n+1,-1);
          dp[0] = dp[1] = 1;
        
        for(int i = 2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
          
      }
  };
  


// Approach 4 - Space optimization
class Solution {
    public:
  
      int countWays(int n) {
         int pichla = 1;
         int usse_pichla = 1;
        
        for(int i = 2; i<=n; i++){
           
            int curr = pichla + usse_pichla;
            usse_pichla = pichla;
            pichla = curr;
            
            
        }
        return pichla;
          
      }
  };

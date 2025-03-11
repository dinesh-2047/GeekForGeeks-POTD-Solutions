// Min Cost Climbing Stairs

// Approach 1  Rec + memo  ( left -> right )
class Solution {
    public:
    int solve(vector<int> &cost , int i , vector<int> &dp){
        if(i>=cost.size()) return 0 ; 
        if(dp[i]!=-1) return dp[i];
        
        return dp[i] = cost[i] + min(solve(cost, i+1,dp) , solve(cost, i+2,dp));
    }
      int minCostClimbingStairs(vector<int>& cost) {
          int n = cost.size();
          vector<int>dp(n+1, -1);
         return min(solve(cost, 0,dp ) , solve(cost, 1,dp));
      }
  };

// Approach 2  again Rec + memo (right -> left)
class Solution {
    public:
    int solve(vector<int> &cost , int n , vector<int> &dp){
        if(n<=0) return 0 ; 
        if(dp[n]!=-1) return dp[n];
        
        return dp[n] = cost[n-1] + min(solve(cost, n-1,dp) , solve(cost, n-2,dp));
    }
      int minCostClimbingStairs(vector<int>& cost) {
          int n = cost.size();
          vector<int>dp(n+1, -1);
         return min(solve(cost, n,dp ) , solve(cost, n-1,dp));
      }
  };

// Approach 1  Tabulation 
class Solution {
    public:
  //   int solve(vector<int> &cost , int n , vector<int> &dp){
  //       if(n<=0) return 0 ; 
  //       if(dp[n]!=-1) return dp[n];
        
  //       return dp[n] = cost[n-1] + min(solve(cost, n-1,dp) , solve(cost, n-2,dp));
  //   }
      int minCostClimbingStairs(vector<int>& cost) {
          int n = cost.size();
          vector<int>dp(n+1, -1);
        
         
         dp[0]=0;
         for(int i =1; i<=n; i++){
             dp[i] = cost[i-1] + min(dp[i-1], dp[i-2]);
         }
         return min(dp[n], dp[n-1]);
      }
  };


// Approach 1 Space optimization 
class Solution {
    public:
  //   int solve(vector<int> &cost , int n , vector<int> &dp){
  //       if(n<=0) return 0 ; 
  //       if(dp[n]!=-1) return dp[n];
        
  //       return dp[n] = cost[n-1] + min(solve(cost, n-1,dp) , solve(cost, n-2,dp));
  //   }
      int minCostClimbingStairs(vector<int>& cost) {
          int n = cost.size();
  
       int  prev = 0;
       int more_prev = 0 ; 
        
         for(int i =1; i<=n; i++){
             int current  = cost[i-1] + min(prev, more_prev);
             more_prev = prev ; 
             prev = current;
         }
         return min(prev, more_prev);
      }
  };
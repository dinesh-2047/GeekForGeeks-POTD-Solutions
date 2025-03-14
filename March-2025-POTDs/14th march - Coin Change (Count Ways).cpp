// Coin Change (Count Ways)


// Approach 1  - > Rec + memo
class Solution {
    public:
    int n ; 
    int solve(vector<int> &coins , int sum , int i, vector<vector<int>> &dp ){
        if(sum == 0) return 1; 
        if(i==n) return 0 ; 
        
       if(dp[i][sum] != -1) return dp[i][sum];
        
        if(sum < coins[i]) return solve(coins , sum , i+1,dp);
        
        int take = solve(coins , sum - coins[i], i,dp);
        int not_take = solve(coins, sum , i+1,dp);
        
        return dp[i][sum] =  take + not_take;
    }
        
        
    
      int count(vector<int>& coins, int sum) {
           n = coins.size();
      vector<vector<int>> dp (n+1, vector<int>(sum+1, -1));
          return solve(coins , sum , 0,dp );
      }
  };

// Approach 2 -> Tabulation 
class Solution {
    public:
  
        
        
    
      int count(vector<int>& coins, int sum) {
          int n = coins.size();
      vector<vector<int>> dp (n+1, vector<int>(sum+1, 0));
          
          
          for(int i = 0 ; i<=n ; i++){
              for(int j = 0 ;j <= sum ; j++){
                  if(j==0){
                      dp[i][j] = 1;
                  }
                  else if(i==0){
                      dp[i][j] = 0;
                  }
                  
                 else if( coins[i-1]<=j){
                      dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                  }
                  else 
                  dp[i][j] =dp[i-1][j];
              } 
          }
          return dp[n][sum];
      }
  };
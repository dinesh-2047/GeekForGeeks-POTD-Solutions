// Coin Change (Minimum Coins)





    // ================== 1️⃣ Recursive (Brute Force) - 2D DP ==================
    // 🔹 Time Complexity: O(2^n)
    // 🔹 Space Complexity: O(n)
   
    class Solution {
        public:
            int n;
        
            int solve(vector<int> &coins, int sum, int i) {
                if (sum == 0) return 0; 
                if (i == n) return 1e9; // Large value instead of INT_MAX
                if (sum < 0) return 1e9;
        
                // Take the current coin
                int take = 1e9;
                if (sum >= coins[i])
                    take = 1 + solve(coins, sum - coins[i], i);
        
                // Skip the current coin
                int not_take = solve(coins, sum, i + 1);
        
                return min(take, not_take);
            }
        
            int minCoins(vector<int> &coins, int sum) {
                n = coins.size();
                int ans = solve(coins, sum, 0);
                return (ans == 1e9 ? -1 : ans); // If impossible, return -1
            }
        };
        


    // ================== 2️⃣ Recursion + Memoization (Top-Down) - 2D DP ==================
    // 🔹 Time Complexity: O(n * sum)
    // 🔹 Space Complexity: O(n * sum) + O(n) (Recursion depth)

    class Solution {
        public:
        int n ; 
        int solve(vector<int> &coins , int sum , int i, vector<vector<int>> &dp ){
            if(sum == 0) return 0; 
              if(i==n) return dp[i][sum] =1e9 ;
              if(sum < 0) return dp[i][sum]= 1e9;
      
              if(dp[i][sum] != -1) return dp[i][sum];
           
              
              int take= 1e9;
              if(sum >= coins[i])
               take = 1 + solve(coins , sum - coins[i], i,dp);
               
              int not_take = solve(coins, sum , i+1,dp);
              
              return dp[i][sum] =  min(take , not_take);
        }
        
          int minCoins(vector<int> &coins, int sum) {
              n = coins.size();
              vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
             
          int ans =  solve(coins, sum , 0,dp );
            return (ans == 1e9 )? -1 : ans; // If impossible, return -1
              
          }
      };

    

    // ================== 3️⃣ Tabulation (Bottom-Up) - 2D DP ==================
    // 🔹 Time Complexity: O(n * sum)
    // 🔹 Space Complexity: O(n * sum)
    class Solution {
        public:
        int n ; 
      
        
          int minCoins(vector<int> &coins, int sum) {
              n = coins.size();
              vector<vector<int>> dp(n+1, vector<int>(sum+1, 1e9));
             
                
              for(int i = 1 ; i<=n; i++){
                  for(int j = 0  ; j<=sum ; j++){
                      if(j==0) dp[i][j]= 0;
                      
                      else if (j >= coins[i-1]){
                          dp[i][j] = min(1 + dp[i][j-coins[i-1]] ,dp[i-1][j]);
                      }
                      else dp[i][j] = dp[i-1][j];
                  }
              }
              return (dp[n][sum] == 1e9) ? -1 : dp[n][sum];
          }
      };

   
   
    // ================== 4 Recursive (Brute Force) - 1D DP ==================
    // 🔹 Time Complexity: O(2^sum)
    // 🔹 Space Complexity: O(sum)

    class Solution {
        public:
        int n ; 
      int solve(vector<int> &coins , int sum ){
           if(sum == 0) return 0 ;
         
           if(sum < 0) return 1e9;
           
           int mini = 1e9 ; 
           for(int i = 0 ;i<n ; i++){
              int take = solve(coins , sum - coins[i]);
               if(take != 1e9)
               mini = min(mini , 1+take);
           }
         
           
           return mini;
          
      }
        
          int minCoins(vector<int> &coins, int sum) {
             n = coins.size();
             
             int ans = solve(coins , sum );
             if(ans == 1e9) return -1;
             
             else return ans; 
          }
      };
    

    // ================== 5 Recursion + Memoization (Top-Down) - 1D DP ==================
    // 🔹 Time Complexity: O(n * sum)
    // 🔹 Space Complexity: O(sum) + O(sum) (Recursion depth)
    lass Solution {
        public:
        int n ; 
      int solve(vector<int> &coins , int sum, vector<int> &dp ){
           if(sum == 0) return 0 ;
         
           if(sum < 0) return 1e9;
           
           if(dp[sum] != -1) return dp[sum];
           
           int mini = 1e9 ; 
           for(int i = 0 ;i<n ; i++){
              int take = solve(coins , sum - coins[i],dp);
               if(take != 1e9)
               mini = min(mini , 1+take);
           }
         
           
           return dp[sum] =  mini;
          
      }
        
          int minCoins(vector<int> &coins, int sum) {
             n = coins.size();
             vector<int>dp(sum+1, -1);
             int ans = solve(coins , sum, dp );
             if(ans == 1e9) return -1;
             
             else return ans; 
          }
      };
    

    // ================== 6 Tabulation (Bottom-Up) - 1D DP ==================
    // 🔹 Time Complexity: O(n * sum)
    // 🔹 Space Complexity: O(sum)
    class Solution {
        public :
        int n ;
    
    int minCoins(vector<int> &coins, int sum) {
        n = coins.size();
        vector<int>dp(sum+1, 1e9);
        dp[0] = 0;
       
        for(int i = 1 ; i<=sum ; i++){
            for(int j = 0 ; j<n; j++){
                if(i-coins[j] >= 0 && dp[i-coins[j]]!=INT_MAX)
                dp[i] = min(dp[i] , 1 + dp[i - coins[j]]);
            }
        }
        return (dp[sum]==1e9)?-1:dp[sum];
     }
 };

   
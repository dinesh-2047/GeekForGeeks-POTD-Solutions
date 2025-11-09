// Stock Buy and Sell with Cooldown

class Solution {
  public:
    int solve(int i, int buy, int cool, vector<int> &prices, int &n, vector<vector<vector<int>>> &dp){
        if(i>=n)
          return 0;
        if(dp[i][buy][cool] != -1)
          return dp[i][buy][cool];
        
        int ans = 0;
        
        if(buy){
            if(cool){
                ans = solve(i+1, 1, 0, prices, n, dp);
            }
            else{
                int buyNow = -prices[i] + solve(i+1, 0, 0, prices, n, dp);
                int skip = solve(i+1, 1, 0, prices, n, dp);
                ans = max(buyNow, skip);
            }
            
        }
        else{
            int sell = prices[i] + solve(i+1, 1, 1, prices, n, dp);
            int hold = solve(i+1, 0, 0, prices, n, dp);
            ans = max(sell, hold);
        }
        
        return dp[i][buy][cool] = ans;
        
    }
  
    int maxProfit(vector<int> &arr) {
     int n = arr.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(2, -1)));
        return solve(0, 1, 0, arr, n, dp);
    }
};
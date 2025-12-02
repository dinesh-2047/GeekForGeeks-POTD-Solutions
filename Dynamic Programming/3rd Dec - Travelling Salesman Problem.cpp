// Travelling Salesman Problem

class Solution {
  public:
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        
        vector<vector<int>> dp(n, vector<int>((1<<n), -1));

        function<int(int,int)> min_cost = [&](int ind, int mask) -> int {
            
            if(mask == 0) return cost[ind][0];

            if(dp[ind][mask] != -1) return dp[ind][mask];

            int ans = INT_MAX;
            for(int nxt = 0; nxt < n; nxt++) {
                if(mask & (1 << nxt)) {
                    ans = min(ans, cost[ind][nxt] + 
                              min_cost(nxt, mask ^ (1 << nxt)));
                }
            }
            return dp[ind][mask] = ans;
        };
        
        int fullMask = (1 << n) - 1;
        return min_cost(0, fullMask ^ 1);
    }
};
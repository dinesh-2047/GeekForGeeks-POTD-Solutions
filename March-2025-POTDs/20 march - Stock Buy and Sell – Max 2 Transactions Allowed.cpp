// Stock Buy and Sell – Max 2 Transactions Allowed



class Solution {
public:
    int n;

    // 1️⃣ **Recursive Approach (TLE)**
    // Time Complexity: Exponential O(2^N)
    // Space Complexity: O(N) (Recursion Stack)
    int solveRec(vector<int>& prices, int i, int transaction) {
        if (i == n || transaction == 4) return 0; // Base case: End of array or max transactions (2 buys + 2 sells)

        int profit = 0;
        if (transaction % 2 == 0) {
            int buyStock = -prices[i] + solveRec(prices, i + 1, transaction + 1);
            int skipStock = solveRec(prices, i + 1, transaction);
            profit = max(buyStock, skipStock);
        } else {
            int sellStock = prices[i] + solveRec(prices, i + 1, transaction + 1);
            int skipStock = solveRec(prices, i + 1, transaction);
            profit = max(sellStock, skipStock);
        }
        return profit;
    }

    int maxProfitRec(vector<int>& prices) {
        n = prices.size();
        return solveRec(prices, 0, 0);
    }

    // 2️⃣ **Recursive + Memoization Approach**
    // Time Complexity: O(N * 4) = O(N)
    // Space Complexity: O(N * 4) + O(N) (Recursion Stack)
    int solveMemo(vector<int>& prices, int i, int transaction, vector<vector<int>>& dp) {
        if (i == n || transaction == 4) return 0;

        if (dp[i][transaction] != -1) return dp[i][transaction];

        int profit = 0;
        if (transaction % 2 == 0) {
            int buyStock = -prices[i] + solveMemo(prices, i + 1, transaction + 1, dp);
            int skipStock = solveMemo(prices, i + 1, transaction, dp);
            profit = max(buyStock, skipStock);
        } else {
            int sellStock = prices[i] + solveMemo(prices, i + 1, transaction + 1, dp);
            int skipStock = solveMemo(prices, i + 1, transaction, dp);
            profit = max(sellStock, skipStock);
        }

        return dp[i][transaction] = profit;
    }

    int maxProfitMemo(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return solveMemo(prices, 0, 0, dp);
    }

    // 3️⃣ **Tabulation Approach (Bottom-Up DP)**
    // Time Complexity: O(N * 4) = O(N)
    // Space Complexity: O(N * 4)
    int maxProfitTabu(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(4 + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int transaction = 3; transaction >= 0; transaction--) {
                int profit = 0;
                if (transaction % 2 == 0) {
                    int buyStock = -prices[i] + dp[i + 1][transaction + 1];
                    int skipStock = dp[i + 1][transaction];
                    profit = max(buyStock, skipStock);
                } else {
                    int sellStock = prices[i] + dp[i + 1][transaction + 1];
                    int skipStock = dp[i + 1][transaction];
                    profit = max(sellStock, skipStock);
                }
                dp[i][transaction] = profit;
            }
        }
        return dp[0][0];
    }

    // 4️⃣ **Space Optimized Approach (2D DP)**
    // Time Complexity: O(N * 4) = O(N)
    // Space Complexity: O(2 * 4) = O(4) ≈ O(1)
    int maxProfitSO2D(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(4, 0), curr(4, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int transaction = 3; transaction >= 0; transaction--) {
                int profit = 0;
                if (transaction % 2 == 0) {
                    int buyStock = -prices[i] + ahead[transaction + 1];
                    int skipStock = ahead[transaction];
                    profit = max(buyStock, skipStock);
                } else {
                    int sellStock = prices[i] + ahead[transaction + 1];
                    int skipStock = ahead[transaction];
                    profit = max(sellStock, skipStock);
                }
                curr[transaction] = profit;
            }
            ahead = curr;
        }
        return ahead[0];
    }

    // 5️⃣ **Fully Space Optimized Approach (1D DP)**
    // Time Complexity: O(N * 4) = O(N)
    // Space Complexity: O(4) = O(1)
    int maxProfitSO1D(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(4, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int transaction = 3; transaction >= 0; transaction--) {
                int profit = 0;
                if (transaction % 2 == 0) {
                    int buyStock = -prices[i] + dp[transaction + 1];
                    int skipStock = dp[transaction];
                    profit = max(buyStock, skipStock);
                } else {
                    int sellStock = prices[i] + dp[transaction + 1];
                    int skipStock = dp[transaction];
                    profit = max(sellStock, skipStock);
                }
                dp[transaction] = profit;
            }
        }
        return dp[0];
    }
};


// Stock Buy and Sell – Max K Transactions Allowed

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Using (k, buy) as state variables
class Solution2 {
public:
    int n;

    // Recursive Solution
    int solveRec(vector<int>& prices, int k, int i, bool buy) {
        if (k == 0 || i == n) return 0;

        int profit = 0;
        if (buy) {  // Buy
            int buyKaro = -prices[i] + solveRec(prices, k, i + 1, false);
            int skip = solveRec(prices, k, i + 1, true);
            profit = max(buyKaro, skip);
        } else {  // Sell
            int sellKaro = prices[i] + solveRec(prices, k - 1, i + 1, true);
            int skip = solveRec(prices, k, i + 1, false);
            profit = max(sellKaro, skip);
        }
        return profit;
    }

    // Memoized Solution
    int solveMemo(vector<int>& prices, int k, int i, bool buy, vector<vector<vector<int>>>& dp) {
        if (k == 0 || i == n) return 0;
        if (dp[i][k][buy] != -1) return dp[i][k][buy];

        int profit = 0;
        if (buy) {  // Buy
            int buyKaro = -prices[i] + solveMemo(prices, k, i + 1, false, dp);
            int skip = solveMemo(prices, k, i + 1, true, dp);
            profit = max(buyKaro, skip);
        } else {  // Sell
            int sellKaro = prices[i] + solveMemo(prices, k - 1, i + 1, true, dp);
            int skip = solveMemo(prices, k, i + 1, false, dp);
            profit = max(sellKaro, skip);
        }
        return dp[i][k][buy] = profit;
    }

    // Tabulation Solution
    int solveTabu(vector<int>& prices, int k) {
        n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));

        for (int i = n - 1; i >= 0; i--) {
            for (int transactions = 1; transactions <= k; transactions++) {
                dp[i][transactions][1] = max(-prices[i] + dp[i + 1][transactions][0], dp[i + 1][transactions][1]);
                dp[i][transactions][0] = max(prices[i] + dp[i + 1][transactions - 1][1], dp[i + 1][transactions][0]);
            }
        }
        return dp[0][k][1];
    }

    // Space Optimized Solution
    int solveSO(vector<int>& prices, int k) {
        n = prices.size();
        vector<vector<int>> curr(k + 1, vector<int>(2, 0));
        vector<vector<int>> next(k + 1, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int transactions = 1; transactions <= k; transactions++) {
                curr[transactions][1] = max(-prices[i] + next[transactions][0], next[transactions][1]);
                curr[transactions][0] = max(prices[i] + next[transactions - 1][1], next[transactions][0]);
            }
            next = curr;
        }
        return next[k][1];
    }
};

// Approach 2: Using a single integer to track the operation number
class Solution1 {
public:
    int n;

    // Recursive Solution
    int solveRec(vector<int>& prices, int k, int i, int operationNo) {
        if (i == n) return 0;
        if (operationNo == 2 * k) return 0;

        int profit = 0;
        if (operationNo % 2 == 0) {  // Buy
            int buy = -prices[i] + solveRec(prices, k, i + 1, operationNo + 1);
            int skip = solveRec(prices, k, i + 1, operationNo);
            profit = max(buy, skip);
        } else {  // Sell
            int sell = prices[i] + solveRec(prices, k, i + 1, operationNo + 1);
            int skip = solveRec(prices, k, i + 1, operationNo);
            profit = max(sell, skip);
        }
        return profit;
    }

    // Memoized Solution
    int solveMemo(vector<int>& prices, int k, int i, int operationNo, vector<vector<int>>& dp) {
        if (i == n) return 0;
        if (operationNo == 2 * k) return 0;
        if (dp[i][operationNo] != -1) return dp[i][operationNo];

        int profit = 0;
        if (operationNo % 2 == 0) {  // Buy
            int buy = -prices[i] + solveMemo(prices, k, i + 1, operationNo + 1, dp);
            int skip = solveMemo(prices, k, i + 1, operationNo, dp);
            profit = max(buy, skip);
        } else {  // Sell
            int sell = prices[i] + solveMemo(prices, k, i + 1, operationNo + 1, dp);
            int skip = solveMemo(prices, k, i + 1, operationNo, dp);
            profit = max(sell, skip);
        }
        return dp[i][operationNo] = profit;
    }

    // Tabulation Solution
    int solveTabu(vector<int>& prices, int k) {
        n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 2 * k - 1; j >= 0; j--) {
                int profit = 0;
                if (j % 2 == 0) {  // Buy
                    int buy = -prices[i] + dp[i + 1][j + 1];
                    int skip = dp[i + 1][j];
                    profit = max(buy, skip);
                } else {  // Sell
                    int sell = prices[i] + dp[i + 1][j + 1];
                    int skip = dp[i + 1][j];
                    profit = max(sell, skip);
                }
                dp[i][j] = profit;
            }
        }
        return dp[0][0];
    }

    // Space Optimized Solution
    int solveSO(vector<int>& prices, int k) {
        n = prices.size();
        vector<int> curr(2 * k + 1, 0);
        vector<int> next(2 * k + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 2 * k - 1; j >= 0; j--) {
                int profit = 0;
                if (j % 2 == 0) {  // Buy
                    int buy = -prices[i] + next[j + 1];
                    int skip = next[j];
                    profit = max(buy, skip);
                } else {  // Sell
                    int sell = prices[i] + next[j + 1];
                    int skip = next[j];
                    profit = max(sell, skip);
                }
                curr[j] = profit;
            }
            next = curr;
        }
        return next[0];
    }
};

/*
Time and Space Complexity:
Approach 2:
- Recursion: O(2^N), O(N) stack space.
- Memoization: O(N * K * 2), O(N * K * 2) extra space.
- Tabulation: O(N * K * 2), O(N * K * 2) space.
- Space Optimization: O(N * K), O(K * 2) space.

Approach 1:
- Recursion: O(2^N), O(N) stack space.
- Memoization: O(N * 2K), O(N * 2K) extra space.
- Tabulation: O(N * 2K), O(N * 2K) space.
- Space Optimization: O(N * 2K), O(2K) space.
*/

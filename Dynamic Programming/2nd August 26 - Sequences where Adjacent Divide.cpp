// Sequences where Adjacent Divide



class Solution {
public:
    vector<vector<int>> dp;
    int solve(int n, int m, int prev) {
        if (n == 0)
            return 1;

        if (dp[n][prev] != -1)
            return dp[n][prev];

        int result = 0;

        for (int j = 1; j <= m; j++) {
            if (prev == 0) {
                result += solve(n - 1, m, j);
            }
            else if (prev % j == 0 || j % prev == 0) {
                result += solve(n - 1, m, j);
            }
        }

        return dp[n][prev] = result;
    }

    int count(int n, int m) {
        dp.assign(n + 1, vector<int>(m + 1, -1));
        return solve(n, m, 0);
    }
};
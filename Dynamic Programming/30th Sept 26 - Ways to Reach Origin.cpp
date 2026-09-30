// Ways to Reach Origin


class Solution {
  public:
    const int MOD = 1e9 + 7;
    int dp[501][501];

    int solve(int x, int y) {
        if (x == 0 || y == 0)
            return 1;

        if (dp[x][y] != -1)
            return dp[x][y];

        return dp[x][y] = (solve(x - 1, y) + solve(x, y - 1)) % MOD;
    }

    int ways(int x, int y) {
        memset(dp, -1, sizeof(dp));
        return solve(x, y);
    }
};
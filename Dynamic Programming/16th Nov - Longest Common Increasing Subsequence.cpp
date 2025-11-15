// Longest Common Increasing Subsequence

class Solution {
  public:
    int LCIS(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();

       vector<int>dp(n, 0);

        for (int i = 0; i < m; i++) {
            int current = 0;
            for (int j = 0; j < n; j++) {
                if (b[i] == a[j]) {
                    dp[j] =max(dp[j], current + 1);
                } else if (b[i] > a[j]) {
                    current = max(current, dp[j]);
                }
            }
        }

        int result = 0;
        for (int v : dp) {
            result = max(result, v);
        }

        return result;
    }
};
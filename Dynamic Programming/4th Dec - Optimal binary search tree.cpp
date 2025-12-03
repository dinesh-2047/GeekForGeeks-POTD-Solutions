// Optimal binary search tree

class Solution {
  public:
    int minCost(vector<int> &keys, vector<int> &freq) {
         
        int n = keys.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // prefix sum of frequencies
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + freq[i];
        }

        // base case : single key
        for (int i = 0; i < n; i++) {
            dp[i][i] = freq[i];
        }

        // L = length of subtree
        for (int L = 2; L <= n; L++) {
            for (int i = 0; i + L - 1 < n; i++) {
                
                int j = i + L - 1;
                dp[i][j] = INT_MAX;

                for (int k = i; k <= j; k++) {

                    int leftCost  = (k > i) ? dp[i][k - 1] : 0;
                    int rightCost = (k < j) ? dp[k + 1][j] : 0;

                    int sumFreq = prefix[j + 1] - prefix[i];

                    dp[i][j] = min(dp[i][j], leftCost + rightCost + sumFreq);
                }
            }
        }

        return dp[0][n - 1];
    }
};
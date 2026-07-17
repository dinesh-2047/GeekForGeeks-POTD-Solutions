// Cut Matrix

class Solution {
public:
    static const int MOD = 1000000007;

    int findWays(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> suff(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                suff[i][j] = matrix[i][j]
                           + suff[i + 1][j]
                           + suff[i][j + 1]
                           - suff[i + 1][j + 1];
            }
        }

        vector<vector<vector<int>>> dp(
            k + 1,
            vector<vector<int>>(n, vector<int>(m, 0))
        );

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (suff[i][j] > 0)
                    dp[1][i][j] = 1;
            }
        }

        for (int cuts = 2; cuts <= k; cuts++) {

            vector<vector<int>> rowSum(n + 1, vector<int>(m, 0));
            vector<vector<int>> colSum(n, vector<int>(m + 1, 0));

            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    rowSum[i][j] = (dp[cuts - 1][i][j] + rowSum[i + 1][j]) % MOD;
                    colSum[i][j] = (dp[cuts - 1][i][j] + colSum[i][j + 1]) % MOD;
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {

                    if (suff[i][j] == 0)
                        continue;

                    int low = i + 1, high = n, firstRow = n;
                    while (low <= high) {
                        int mid = (low + high) / 2;
                        if (suff[mid][j] < suff[i][j]) {
                            firstRow = mid;
                            high = mid - 1;
                        } else {
                            low = mid + 1;
                        }
                    }

                    int low2 = j + 1, high2 = m, firstCol = m;
                    while (low2 <= high2) {
                        int mid = (low2 + high2) / 2;
                        if (suff[i][mid] < suff[i][j]) {
                            firstCol = mid;
                            high2 = mid - 1;
                        } else {
                            low2 = mid + 1;
                        }
                    }

                    long long ans = 0;

                    if (firstRow < n)
                        ans = (ans + rowSum[firstRow][j]) % MOD;

                    if (firstCol < m)
                        ans = (ans + colSum[i][firstCol]) % MOD;

                    dp[cuts][i][j] = ans;
                }
            }
        }

        return dp[k][0][0];
    }
};
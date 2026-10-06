// Longest Increasing Path in Matrix

class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    vector<int> dir = {0, 1, 0, -1, 0};

    int dfs(vector<vector<int>>& matrix, int i, int j) {
        if (dp[i][j] != -1)
            return dp[i][j];

        int result = 1;

        for (int k = 0; k < 4; k++) {
            int ni = i + dir[k];
            int nj = j + dir[k + 1];

            if (ni >= 0 && ni < n &&
                nj >= 0 && nj < m &&
                matrix[ni][nj] > matrix[i][j]) {
                result = max(result, 1 + dfs(matrix, ni, nj));
            }
        }

        return dp[i][j] = result;
    }

    int longIncPath(vector<vector<int>> &matrix, int n, int m) {
        this->n = n;
        this->m = m;

        dp.assign(n, vector<int>(m, -1));

        int result = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result = max(result, dfs(matrix, i, j));
            }
        }

        return result;
    }
};
// 2D Difference Array


class Solution {
public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat, vector<vector<int>>& opr) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> diff(m + 1, vector<int>(n + 1, 0));

        for (auto& op : opr) {
            int v = op[0];
            int r1 = op[1];
            int c1 = op[2];
            int r2 = op[3];
            int c2 = op[4];

            diff[r1][c1]     += v;
            diff[r1][c2 + 1] -= v;
            diff[r2 + 1][c1] -= v;
            diff[r2 + 1][c2 + 1] += v;
        }

        for (int i = 0; i < m;i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) diff[i][j] += diff[i - 1][j];
                if (j > 0) diff[i][j] += diff[i][j - 1];
                if (i > 0 && j > 0) diff[i][j] -= diff[i - 1][j - 1];
            }
        }

        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                result[i][j] = mat[i][j] + diff[i][j];

        return result;
    }
};

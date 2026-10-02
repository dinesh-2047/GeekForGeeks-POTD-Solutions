// Coils in a Matrix

class Solution {
public:
    vector<vector<int>> formCoils(int n) {
        n = 4 * n;

        vector<vector<int>> mat(n, vector<int>(n));
        int val = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = val++;
            }
        }

        vector<vector<int>> result(2);

        int top = 0, left = 0;
        int bottom = n - 1, right = n - 2;

        while (top <= bottom && left <= right) {
            for (int i = top; i <= bottom; i++)
                result[0].push_back(mat[i][left]);

            for (int j = left + 1; j <= right; j++)
                result[0].push_back(mat[bottom][j]);

            for (int i = bottom - 1; i > top; i--)
                result[0].push_back(mat[i][right]);

            for (int j = right - 1; j > left + 1; j--)
                result[0].push_back(mat[top + 1][j]);

            top += 2;
            left += 2;
            bottom -= 2;
            right -= 2;
        }

        for (auto &x : result[0]) {
            int row = (x - 1) / n;
            int col = (x - 1) % n;

            int newRow = n - 1 - row;
            int newCol = n - 1 - col;

            result[1].push_back(mat[newRow][newCol]);
        }

        return result;
    }
};
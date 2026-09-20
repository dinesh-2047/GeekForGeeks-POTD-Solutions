// Largest Subsquare Surrounded by X

class Solution {
public:
    int n;
    vector<vector<int>> right, down;

    pair<int, int> solve(vector<vector<char>>& mat, int i, int j) {
        if (i >= n || j >= n)
            return {0, 0};

        if (right[i][j] != -1)
            return {right[i][j], down[i][j]};

        if (mat[i][j] != 'X')
            return {right[i][j] = 0, down[i][j] = 0};

        int r = 1;
        int d = 1;

        if (j + 1 < n)
            r += solve(mat, i, j + 1).first;

        if (i + 1 < n)
            d += solve(mat, i + 1, j).second;

        right[i][j] = r;
        down[i][j] = d;

        return {r, d};
    }

    int largestSubsquare(vector<vector<char>>& mat) {
        n = mat.size();

        right.assign(n, vector<int>(n, -1));
        down.assign(n, vector<int>(n, -1));

        int result = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                solve(mat, i, j);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                int maxSize = min(right[i][j], down[i][j]);

                for (int size = maxSize; size > result; size--) {
                    int bottom = i + size - 1;
                    int lastCol = j + size - 1;

                    if (bottom < n && lastCol < n &&
                        right[bottom][j] >= size &&
                        down[i][lastCol] >= size) {

                        result = size;
                        break;
                    }
                }
            }
        }

        return result;
    }
};
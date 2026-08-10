// Largest Odd Squares with Limited 1s

class Solution {
public:
    vector<int> largestSquare(vector<vector<int>>& mat, vector<vector<int>>& queries, int k) {

        int m= mat.size();
        int n= mat[0].size();
        vector<vector<int>> pref(m+ 1, vector<int>(n+ 1, 0));

        pref[1][1] = mat[0][0];
        for(int j = 1; j < n; j++)
            pref[1][j + 1] += mat[0][j] + pref[1][j];
        for(int i = 1; i < m; i++)
            pref[i + 1][1] += mat[i][0] + pref[i][1];

        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] - pref[i][j] + mat[i][j];

        vector<int> res;
        for (auto it : queries) {
            int i = it[0] + 1;
            int j = it[1] + 1;
            int v = 0;
            while ((i + v <= m) && (i - v > 0) && (j + v <= n) && (j - v > 0)) {
                if (pref[i + v][j + v] - pref[i - v - 1][j + v] - pref[i + v][j - v - 1] + pref[i - v - 1][j - v - 1] > k)
                    break;
                v++;
            }
            res.push_back(2 * v - 1);
        }
        return res;
    }
};
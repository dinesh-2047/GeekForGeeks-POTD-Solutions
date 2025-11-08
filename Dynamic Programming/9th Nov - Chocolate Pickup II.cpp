// Chocolate Pickup II


class Solution {
  public:
    int maxChocolates(int i1, int j1, int j2, vector<vector<int>> &mat, 
                  vector<vector<vector<int>>> &dp) {
    int n = mat.size();
    int m = mat[0].size();

    // calculating row of 2nd robot
    int i2 = i1 + j1 - j2;

    // check if any of the robots
    // is outside the grid
    if (i1 >= n || i2 >= n || j1 >= m || j2 >= m)
        return INT_MIN;

    // check if any of the robots is
    // in a blocked cell
    if (mat[i1][j1] == -1 || mat[i2][j2] == -1)
        return INT_MIN;

    if (i1 == n - 1 && j1 == m - 1 && j2 == m - 1)
        return mat[i1][j1];

    // if result is already computed
    // return the stored value
    if (dp[i1][j1][j2] != -1)
        return dp[i1][j1][j2];

    int ans = INT_MIN;

    // a robot can either move downwards or rightwards
    int dir[2][2] = {{1, 0}, {0, 1}};
    for (auto &d1 : dir) {
        for (auto &d2 : dir) {
            int newRow1 = i1 + d1[0];
            int newCol1 = j1 + d1[1];
            int newCol2 = j2 + d2[1];

            // taking maximum chocolates
            // among all possibilities
            ans = max(ans, maxChocolates(newRow1, newCol1, newCol2, mat, dp));
        }
    }
    ans += mat[i1][j1];

    // if both robots are not in the same cell
    if (i1 != i2)
        ans += mat[i2][j2];

    return dp[i1][j1][j2] = ans;
}

int chocolatePickup(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    return max(0, maxChocolates(0, 0, 0, mat, dp));
}
};
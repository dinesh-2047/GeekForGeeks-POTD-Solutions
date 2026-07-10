// Longest Possible Route in a Matrix with Hurdles



class Solution {
  public:
  int m , n; 
  vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}}; 
  vector<vector<bool>> visited; 
  int solve(vector<vector<int>> &mat, int i, int j, int xd, int yd) {
    if (i == xd && j == yd)
        return 0;

    visited[i][j] = true;

    int result = -1;

    for (auto &d : directions) {
        int ni = i + d[0];
        int nj = j + d[1];

        if (ni < 0 || ni >= m || nj < 0 || nj >= n)
            continue;

        if (mat[ni][nj] == 0 || visited[ni][nj])
            continue;

        int cur = solve(mat, ni, nj, xd, yd);

        if (cur != -1)
            result = max(result, cur + 1);
    }

    visited[i][j] = false;

    return result;
}
    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {
        m = mat.size();
        n = mat[0].size();
        
        visited.assign(m, vector<bool>(n , false));
      
        
        return solve(mat, xs, ys , xd, yd );
        
    }
};
// Min Steps by Knight

class Solution {
  public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        int sx = knightPos[0] - 1, sy = knightPos[1] - 1;
        int tx = targetPos[0] - 1, ty = targetPos[1] - 1;

        if (sx == tx && sy == ty)
            return 0;

        vector<vector<int>> dir = {
            {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
            {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
        };

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        q.push({sx, sy});
        dist[sx][sy] = 0;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto &d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                    dist[nx][ny] == -1) {

                    dist[nx][ny] = dist[x][y] + 1;

                    if (nx == tx && ny == ty)
                        return dist[nx][ny];

                    q.push({nx, ny});
                }
            }
        }

        return -1;
    }
};


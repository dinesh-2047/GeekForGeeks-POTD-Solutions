// Geek in a Maze

class Solution {
public:
    int numberOfCells(int r, int c, int u, int d, vector<vector<char>> &mat) {
        int m = mat.size();
        int n = mat[0].size();

        if (mat[r][c] == '#')
            return 0;

        int result = 0;

        vector<vector<int>> dist(m, vector<int>(n, 1e9));

        deque<tuple<int, int>> q;

        q.push_front({r, c});
        dist[r][c] = 0;

        vector<vector<int>> directions = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop_front();

            for (int dirs = 0; dirs < 4; dirs++) {
                auto dir = directions[dirs];

                int newi = i + dir[0];
                int newj = j + dir[1];

                if (newi < 0 || newj < 0 ||
                    newi >= m || newj >= n)
                    continue;

                if (mat[newi][newj] == '#')
                    continue;

                int cost = (dirs == 0);

                if (dist[i][j] + cost < dist[newi][newj]) {
                    dist[newi][newj] = dist[i][j] + cost;

                    if (cost)
                        q.push_back({newi, newj});
                    else
                        q.push_front({newi, newj});
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (dist[i][j] == 1e9)
                    continue;

                int up = dist[i][j];
                int down = up + (i - r);

                if (up <= u && down <= d)
                    result++;
            }
        }

        return result;
    }
};
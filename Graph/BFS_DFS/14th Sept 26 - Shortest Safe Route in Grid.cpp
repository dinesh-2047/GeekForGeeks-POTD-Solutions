// Shortest Safe Route in Grid


class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int shortestPath(vector<vector<int>> &mat) {
        m = mat.size();
        n = mat[0].size();

        vector<vector<int>> temp = mat;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    temp[i][j] = 0;

                    for(auto &dir : directions) {
                        int newi = i + dir[0];
                        int newj = j + dir[1];

                        if(newi >= 0 && newj >= 0 &&
                           newi < m && newj < n) {
                            temp[newi][newj] = 0;
                        }
                    }
                }
            }
        }

        queue<pair<int,int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            if(temp[i][0] == 1) {
                q.push({i, 0});
                visited[i][0] = 1;
            }
        }

        int result = 1;

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                auto [i, j] = q.front();
                q.pop();

                if(j == n - 1)
                    return result;

                for(auto &dir : directions) {
                    int newi = i + dir[0];
                    int newj = j + dir[1];

                    if(newi >= 0 && newj >= 0 &&
                       newi < m && newj < n &&
                       temp[newi][newj] == 1 &&
                       !visited[newi][newj]) {

                        visited[newi][newj] = 1;
                        q.push({newi, newj});
                    }
                }
            }

            result++;
        }

        return -1;
    }
};
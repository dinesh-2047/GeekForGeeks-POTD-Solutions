// Towers Reaching Both Stations

class Solution {
  public:
    vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};

    int countCoordinates(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> br(m, vector<int>(n, 0));
        vector<vector<int>> tl(m, vector<int>(n, 0));

        queue<pair<int,int>> q;

        for(int i = 0; i < m; i++){
            br[i][0] = 1;
            q.push({i,0});
        }

        for(int j = 1; j < n; j++){
            br[0][j] = 1;
            q.push({0,j});
        }

        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();

            for(auto &dir : directions){
                int newi = i + dir[0];
                int newj = j + dir[1];

                if(newi < 0 || newi >= m || newj < 0 || newj >= n || br[newi][newj])
                    continue;

                if(mat[newi][newj] >= mat[i][j]){
                    br[newi][newj] = 1;
                    q.push({newi,newj});
                }
            }
        }

        int result = 0;

        for(int i = 0; i < m; i++){
            tl[i][n-1] = 1;
            if(br[i][n-1]) result++;
            q.push({i,n-1});
        }

        for(int j = 0; j < n-1; j++){
            tl[m-1][j] = 1;
            if(br[m-1][j]) result++;
            q.push({m-1,j});
        }

        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();

            for(auto &dir : directions){
                int newi = i + dir[0];
                int newj = j + dir[1];

                if(newi < 0 || newi >= m || newj < 0 || newj >= n || tl[newi][newj])
                    continue;

                if(mat[newi][newj] >= mat[i][j]){
                    if(br[newi][newj])
                        result++;
                    tl[newi][newj] = 1;
                    q.push({newi,newj});
                }
            }
        }

        return result;
    }
};
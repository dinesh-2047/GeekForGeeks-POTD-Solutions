// Distance of nearest cell having 1



// Approach using bfs 

class Solution {
  public:
  vector<vector<int>>directions = {{0,1}, {1, 0}, {0,-1}, {-1, 0}};
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>>result(m , vector<int>(n , 0));
        vector<vector<bool>>visited(m, vector<bool>(n , false));
        
        queue<pair<int , pair<int , int>>>q; 
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n; j++){
                if(grid[i][j] ==1 ){
                    q.push({i , {j , 0}});
                    visited[i][j] =true; 
                }
            }
        }
        
        while(!q.empty()){
            auto curr = q.front(); 
            q.pop();
            
            int i = curr.first; 
            int j = curr.second.first; 
            int dist = curr.second.second; 
            
            result[i][j] = dist; 
            
            for(auto &dir : directions){
                int newi = i + dir[0];
                int newj = j + dir[1];
                
                if(newi < m && newi >= 0 && newj < n && newj >=0 && !visited[newi][newj] ){
                    visited[newi][newj] = true; 
                    result[newi][newj] = dist + 1; 
                    q.push({newi, {newj, dist +1}});
                }
            }
        }
        return result; 
        
    }
};
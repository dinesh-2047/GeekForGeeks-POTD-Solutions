// Replace O's with X's


// Approach  using bfs 

class Solution {
  public:
  
  vector<vector<int>>directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void fill(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        
        queue<pair<int, int>>q; 
        //first row
        for(int j = 0 ; j  < n; j++){
            if(grid[0][j] =='O'){
                q.push({0, j});
                grid[0][j] = 'T';
            }
        }
        //first col 
        for(int i = 0 ; i  < m ; i++){
            if(grid[i][0] =='O'){
                q.push({i , 0});
                grid[i][0] = 'T';
            }
        }
        
        //last row
        for(int j =0 ; j  < n; j++){
            if(grid[m-1][j] == 'O'){
                q.push({m-1, j});
                grid[m-1][j] = 'T';
            }
        }
        
        //last col 
        for(int i = 0 ; i  < m; i++){
            if(grid[i][n-1] == 'O'){
                q.push({i, n-1});
                grid[i][n-1] = 'T';
            }
        }
        
        
       while(!q.empty()){
           auto curr = q.front();
           q.pop();
           int i = curr.first; 
           int j = curr.second; 
           
           for(auto &dir : directions){
               int newi = i + dir[0];
               int newj = j  +dir[1];
               
               if(newi < m && newi >=0 && newj <n && newj >=0 && grid[newi][newj] == 'O'){
                   grid[newi][newj] = 'T';
                   q.push({newi, newj});
               }
           }
       }
       
       for(int i = 0 ; i < m; i++){
           for(int j = 0 ; j  <n ;j++){
               if(grid[i][j] == 'O'){
                   grid[i][j] ='X';
               }
               else if(grid[i][j] == 'T'){
                   grid[i][j] = 'O';
               }
           }
       }
        
    }
};
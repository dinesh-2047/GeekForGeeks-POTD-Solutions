// Rat in a Maze


class Solution {
  public:
  int n , m ; 
  void solve(int i, int j , vector<vector<int>> &maze, string curr, vector<string> &result, vector<vector<bool>> &visited ){
      if(i==m-1 && j == n-1) {
          result.push_back(curr);
          return ; 
      }
      
      if(i < 0 || j < 0 || j >= n || i >= m || visited[i][j] || maze[i][j] == 0 ) return; 
      
      visited[i][ j ] = true; 
       solve(i + 1, j , maze, curr + "D", result  , visited);
     solve(i , j - 1, maze, curr + "L", result , visited);
      solve(i, j + 1, maze, curr + "R" , result, visited);
      solve(i - 1, j, maze, curr + "U" , result , visited);
     

      
      visited[i][j] = false; 
  }
  
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        m = maze.size();
        n = maze[0].size();
        vector<string>result;
        string curr = "";
        vector<vector<bool>>visited(m , vector<bool> (n , false)); 
        solve(0, 0 , maze, curr, result, visited);
        
        return result; 
    }
};
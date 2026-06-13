// Exit Point in a Matrix

class Solution {
  public:
  vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
  int m , n ; 
  vector<int> solve(vector<vector<int>> &mat, int i , int j , int dir){
      if(mat[i][j] == 1){
          dir = (dir + 1)%4; 
          mat[i][j] = 0; 
      }
      
      int newi = i + directions[dir][0];
      int newj = j + directions[dir][1];
      
      if(newi < 0 || newj < 0 || newj >= n || newi >= m ) return {i, j}; 
      
      return solve(mat, newi, newj , dir);
  }
    vector<int> exitPoint(vector<vector<int>>& mat) {
       m = mat.size();
       n = mat[0].size();
       
       return solve(mat, 0 , 0 , 0);
        
    }
};
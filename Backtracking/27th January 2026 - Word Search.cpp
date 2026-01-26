// Word Search

class Solution {
  public:
  int m ,n ;
  vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
  bool dfs(vector<vector<char>> &mat, string &word, int i, int j, int idx){
      if(idx == word.length()) return true; 
      
      if(i < 0 || i >= m || j < 0 || j >= n || mat[i][j] != word[idx]) return false; 
      
      
      char temp  = mat[i][j];
      mat[i][j] = '#';
      
      bool found = false; 
      for(auto &dir : directions){
          int newi = i + dir[0];
          int newj = j + dir[1];
          
          if(dfs(mat, word, newi, newj, idx + 1)) found = true; 
      }
      mat[i][j] =temp; 
      return found; 
  }
  
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        m = mat.size();
        n = mat[0].size();
        
        for(int i = 0; i  < m; i++){
            for(int j =0 ; j  < n ;j++){
                if(dfs(mat, word, i , j, 0 )) return true; 
            }
        }
        return false; 
        
    }
};
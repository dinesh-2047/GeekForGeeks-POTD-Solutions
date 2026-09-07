// Word in Grid - All Occurrences

class Solution {
  public:
  vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1}};
  int m , n , l ; 
  bool check(vector<vector<char>> &mat, string &word, int i , int j , int dx ,int dy){
      for(int k = 0 ; k  < l; k++){
          int newi = i + k * dx; 
          int newj = j + k * dy;
          
          if(newi < 0 || newj < 0 || newi >= m || newj >= n || mat[newi][newj] != word[k]) {
              return false; 
          }
      }
      return true;
  }
  
    vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word) {
       m = mat.size();
       n = mat[0].size();
       l = word.length();
       
       vector<vector<int>> result; 
       
       for(int i= 0 ; i < m; i++){
           for(int j = 0 ; j  < n; j++ ){
               if(mat[i][j] == word[0]){
                   for(auto &dir : directions){
                       int dx = dir[0];
                       int dy = dir[1];
                       if(check(mat, word, i , j , dx , dy)){
                           result.push_back({i,j});
                           break; 
                       }
                   }
               }
           }
       }
        return result; 
    }
};
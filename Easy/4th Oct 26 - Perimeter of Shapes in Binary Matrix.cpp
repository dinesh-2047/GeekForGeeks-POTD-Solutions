// Perimeter of Shapes in Binary Matrix

class Solution {
  public:
  vector<vector<int>> directions = {{0, 1}, {1, 0}, {0,-1}, {-1, 0}};
    int findPerimeter(vector<vector<int>> &mat) {
        int result = 0 ; 
        
        int m = mat.size();
        int n = mat[0].size();
        
        
        for(int i = 0 ; i < m;  i++){
            for(int j = 0 ; j < n; j++){
                
                if(mat[i][j] == 1){
                    result += 4; 
                
                
                for(auto &dir : directions){
                    int newi = i + dir[0];
                    int newj = j + dir[1];
                    
                    if(newi >=0 && newj >= 0 && newi < m && newj < n && mat[newi][newj] == 1){
                        result--;
                    }
                }
                }
            }
        }
        return result; 
        
    }
};
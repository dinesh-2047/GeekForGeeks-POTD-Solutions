// Flood fill Algorithm 

class Solution {
    public:
    vector<vector<int>>directions = {{0,1},{0,-1},{1,0},{-1,0}};
    int originalColor;
    int m, n ;
    
    void dfs(vector<vector<int>> &image, vector<vector<bool>> &visited, int i , int j, int newColor ){
        visited[i][j] = true; 
        image[i][j] = newColor; 
        
        for(auto &dir :directions){
            int newi = i + dir[0];
            int newj = j + dir[1];
            
              if(newi < m && newi >=0 && newj >=0 && newj <n && !visited[newi][newj] ){
                  if(originalColor == image[newi][newj]){
                      dfs(image, visited, newi, newj, newColor);
                  }
              }
        }
    }
    
      vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                    int newColor) {
          m  = image.size();
          n = image[0].size();
          originalColor = image[sr][sc];
  
        if (originalColor == newColor) return image;
          
          vector<vector<bool>> visited(m, vector<bool>(n, false)); 
         dfs(image, visited , sr, sc, newColor);
          return image; 
          
          
      }
  };
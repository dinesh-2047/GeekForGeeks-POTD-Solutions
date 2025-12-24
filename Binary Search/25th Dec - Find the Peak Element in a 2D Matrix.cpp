// Find the Peak Element in a 2D Matrix


// Approach 1 without binary search 
class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        for(int i = 0 ; i  < m; i++){
            for(int j = 0 ; j < n; j++){
                int num = mat[i][j];
                
                int left = j -1 >= 0 ? mat[i][j-1] : INT_MIN;
                int right = j + 1 < n ? mat[i][j + 1] : INT_MIN;
                int top = i - 1 >= 0 ? mat[i-1][j] : INT_MIN;
                int bottom = i + 1 < m ? mat[i + 1][j] : INT_MIN;
                
                if(num >= left  && num >= right && num >= top && num >= bottom){
                    return {i, j};
                }
            }
          
        }
        return {};
        
    }
};



//Approach 2 with binary search

class Solution {
  public:
  int find_max(vector<vector<int>> &mat, int col){
      int maxi = INT_MIN; 
      int row = -1 ; 
      
      for(int i = 0 ; i  < mat.size(); i++){
          if(mat[i][col] > maxi){
              maxi = mat[i][col];
              row = i;
          }
      }
      return row; 
  }
  
  
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        if( n== 1) return {find_max(mat, 0), 0};
        if(m == 1){
            int max_col = 0 ; 
            for(int i = 0 ; i  < n; i++){
                if(mat[0][i] > mat[0][max_col] ) max_col = i ; 
            }
            return {0, max_col};
        }
        
        int l = 0; 
        int r = n-1; 
        
        while(l <= r){
            int mid = l + (r-l)/2; 
            
            int maxRow = find_max(mat, mid);
            
            int left = mid - 1 >= 0 ? mat[maxRow][mid-1] : INT_MIN;
            int right = mid + 1 <n  ? mat[maxRow][mid+ 1] : INT_MIN;
            
            if(mat[maxRow][mid] >= left && mat[maxRow][mid] >= right){
                return {maxRow, mid};
            }
            else if(mat[maxRow][mid] < right) l = mid + 1; 
            else r = mid - 1; 
            
        }
        return {-1, -1};
        
    }
};

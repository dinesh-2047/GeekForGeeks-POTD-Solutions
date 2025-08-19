// Search in fully rotated sorted 2D matrix


// Approach 1 
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int m = mat.size();
        int n = mat[0].size();
        
        for(int i = 0 ; i < m; i++){
            for(int  j= 0 ; j < n; j++){
                if(mat[i][j] == x) return true; 
            }
        }
        return false; 
        
    }
};



//Approach 2 
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int m = mat.size();
        int n = mat[0].size();
        
       int l = 0 ; 
       int r = n * m - 1; 
        while(l <= r){
            
            int mid = l + (r- l )/2; 
            
            int row = mid/n; 
            int col = mid%n; 
            
            int midVal = mat[row][col];
            if(midVal == x) return true; 
            
            int lowVal = mat[l/n][l%n];
            int highVal = mat[r/n][r%n];
            
            if(lowVal <= midVal){
                if(x >= lowVal && x < midVal){
                    r = mid - 1; 
                }
                else l = mid + 1; 
            }
        
        else{
            if(x <= highVal && x > midVal){
                l = mid + 1 ; 
            }
            else r = mid -1 ; 
        }
    }
     return false; 
    }
   
};

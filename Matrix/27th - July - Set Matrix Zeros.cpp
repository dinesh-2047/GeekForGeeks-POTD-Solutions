// Set Matrix Zeros




// Approach 1 using extra space
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        
        int m = mat.size();
        int n = mat[0].size();
        
        queue<pair<int , int>>q; 
        for(int i = 0 ; i  <m; i++){
            for(int j = 0 ; j  <n; j++){
                if(mat[i][j] == 0 ){
                    q.push({i , j});
                }
            }
        }
        
        while(!q.empty()){
            int i = q.front().first; 
            int j = q.front().second ; 
            q.pop();
            
            for(int row = 0 ; row < m ; row++){
                mat[row][j] = 0; 
            }
            for(int col = 0 ; col < n ; col++){
                mat[i][col] = 0;
            }
        }
    }
};





//Approach 2 using O(1) space
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        bool isFirstRowZero = false; 
        bool isFirstColZero = false; 
        
        for(int row = 0 ; row < m; row++){
            if(mat[row][0] == 0) isFirstColZero = true; 
        }
        
        for(int col = 0 ; col < n; col++){
            if(mat[0][col] == 0 ) isFirstRowZero = true; 
        }
        
        
        
        
        
        
        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j < n; j++){
                if(mat[i][j] == 0 ){
                    mat[i][0] = 0 ; 
                    mat[0][j] = 0 ;
                }
            }
        }
        
        for(int i = 1 ; i <m; i++){
            for(int j = 1; j <n ;j++){
                if(mat[0][j] == 0 || mat[i][0] == 0 ){
                    mat[i][j] = 0; 
                }
            }
        }
        
        
        if(isFirstRowZero){
            for(int col = 0; col <n; col++){
                mat[0][col] = 0 ;
            }
        }
        
        if(isFirstColZero){
            for(int row = 0 ; row < m; row++){
                mat[row][0] = 0;
            }
        }
    }
};
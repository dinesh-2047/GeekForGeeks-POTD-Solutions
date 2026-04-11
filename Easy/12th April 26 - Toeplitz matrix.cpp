// Toeplitz matrix

class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& mat) {
       int m = mat.size();
       int n = mat[0].size();
       
        for(int i = 1;i < m; i++){
            for(int  j = 1 ; j  < n; j++){
                if(i -1 >= 0 && j - 1 >=0 && mat[i][j] != mat[i - 1][j - 1]) return false; 
            }
        }
        return true; 
    }
};
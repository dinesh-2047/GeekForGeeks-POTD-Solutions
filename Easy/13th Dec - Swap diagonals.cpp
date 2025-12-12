// Swap diagonals


class Solution {
  public:
    void swapDiagonal(vector<vector<int>> &mat) {
        int n = mat.size();
      int i = 0 ; 
      int j = n-1; 
       while(i <n && j >=0 ){
           swap(mat[i][i], mat[i][j]);
           i++;
           j--;
       }
       
        
    }
};

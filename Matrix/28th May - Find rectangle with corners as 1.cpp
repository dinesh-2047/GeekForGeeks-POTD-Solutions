// Find rectangle with corners as 1




class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& matrix) {
         int rows = matrix.size();
        int cols = matrix[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = i + 1; j < rows; j++){
                int cnt = 0;
                for(int k = 0; k < cols; k++){
                    if(matrix[i][k] == 1 && matrix[j][k] == 1)
                    cnt++;
                    if(cnt == 2)
                    return true;
                }
            }
        }
        return false;
    }
};



//can be solved by multiple approaches 
// Coverage of all Zeros in a Binary Matrix/

class Solution {
  public:
    int findCoverage(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        
        int result = 0 ; 
        
        for(int i = 0 ;i < m; i++){
            for(int j = 0 ; j  < n; j++){
                if(mat[i][j] == 0){
                    int count = 0 ; 
                    
                    for(int col = 0 ; col < j; col++){
                        if(mat[i][col] == 1){
                            count++;
                            break; 
                        }
                    }
                    for(int col = j + 1 ; col < n; col++){
                        if(mat[i][col] == 1){
                            count++;
                            break; 
                        }
                    }
                    
                    for(int row = 0 ; row < i; row++){
                        if(mat[row][j] == 1) {
                            count++;
                            break; 
                        }
                    }
                    for(int row = i + 1 ; row < m; row++){
                        if(mat[row][j] == 1) {
                            count++;
                            break; 
                        }
                    }
                    result+=count; 
                }
            }
        }
        return result; 
        
    }
};

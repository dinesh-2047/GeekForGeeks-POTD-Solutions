// Number of submatrix have sum X


class Solution {
  public:
    int countSquare(vector<vector<int>>& mat, int x) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>>pref(m + 1, vector<int>(n + 1));
        
        for(int i = 1; i  <= m; i++){
            for(int j = 1; j <= n ; j++){
                pref[i][j] = mat[i-1][j-1] + pref[i-1][j] + pref[i][j-1] ;
                pref[i][j] -= pref[i - 1][j- 1];
                
            }
        }
        
        int result = 0 ; 
        
        for(int i = 0 ; i  < m ; i++){
            for(int j = 0 ; j < n; j++){
                for(int k = 1; k <= min(m-i, n-j); k++){
                    int sum = pref[i+k][j+k] - pref[i][j+k] - pref[i+k][j] + pref[i][j];
                    if(sum == x ) result++;
                }
                
            }
        }
        return result;
    }
};
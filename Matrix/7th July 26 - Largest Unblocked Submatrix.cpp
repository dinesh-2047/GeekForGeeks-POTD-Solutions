// Largest Unblocked Submatrix


class Solution {
  public:
    int largestArea(int n, int m, int k, vector<vector<int>> &arr) {
        if(k == 0 ) return m * n; 
        
        vector<int> row(n, 1), col(m , 1);
        
        for(auto &v : arr){
            row[v[0] - 1] = 0; 
            col[v[1] - 1] = 0; 
        }
        
        
        int countr = 0 ; 
        int maxr = 0; 
        
        for(auto &it : row){
            if(it == 1){
                countr++;
                maxr = max(countr, maxr);
            }
            else countr = 0 ; 
        }
        
        int result = maxr; 
        countr = 0 ;
        maxr = 0 ; 
        
        for(auto &it : col){
            if(it == 1){
                countr++;
                maxr = max(countr, maxr);
            }
            else countr = 0 ; 
        }
        result *= maxr; 
        return result;
        
    }
};
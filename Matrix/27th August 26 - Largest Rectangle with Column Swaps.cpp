// Largest Rectangle with Column Swaps

class Solution {
  public:
    int maxArea(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int result = 0;
        
        vector<int>h(n);
        for(int i = 0; i  < m ; i++ ){
            for(int j = 0 ;j   < n; j++){
                h[j] = mat[i][j] ? h[j] + 1 : 0 ; 
            }
            vector<int> hc = h; 
            sort(rbegin(hc), rend(hc));
            
            for(int j = 0 ; j  < n ;j++) result = max(result, hc[j]*(j+1));
        }
        return result; 
        
    }
};
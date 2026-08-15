// Min Product Subset

class Solution {
  public:
    int minProd(vector<int>& arr) {
        int n = arr.size();
        
        int result = 1e9; 
        
        for(int mask = 1; mask < (1<<n); mask++){
            int pro = 1; 
            for(int i = 0 ; i  < n; i++){
                if(mask &(1 << i )){
                    pro *= arr[i];
                }
            }
            result = min(result, pro);
        }
        return result; 
        
    }
};
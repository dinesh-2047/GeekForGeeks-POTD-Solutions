// Minimum Toogles to partition

class Solution {
  public:
    int minToggle(vector<int>& arr) {
        int n = arr.size();
        
        int count0  = 0 ; 
        for(auto &x : arr ) {
            if(x == 0 ) count0++;
        }
        
        int right0 = count0 ; 
        int left1 = 0 ; 
        int result = count0; 
        for(auto &x : arr){
            if(x == 1){
                left1++;
            }
            else right0--;
            
            result = min(result, left1 + right0);
        }
        return result;
        
    }
};
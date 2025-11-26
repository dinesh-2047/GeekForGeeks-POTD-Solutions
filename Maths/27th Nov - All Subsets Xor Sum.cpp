// All Subsets Xor Sum


class Solution {
  public:
    int subsetXORSum(vector<int>& arr) {
        int n = arr.size();
        
        int xorr = 0 ; 
        
        for(int i = 0 ; i <n; i++){
            xorr |= arr[i];
        }
        
        int val = 1 << (n - 1);
        
        return val * xorr; 
        
    }
};
// Maximum Subset XOR

class Solution {
  public:
    int maxSubsetXOR(vector<int> &arr) {
        int n = arr.size();
        
        int xorr = 0 ; 
        
        while(true){
            int x = *max_element(begin(arr), end(arr));
            if(x == 0 ) return xorr; 
            
            xorr = max(xorr, x^xorr);
            
            for(int i = 0 ; i  < n; i++){
                arr[i] = min(arr[i], arr[i]^x);
            }
        }
        return xorr; 
        
    }
};
// Max Xor Subarray of size K

class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n = arr.size();
        
        int xorr = 0 ; 
        int result = 0 ; 
        
        int i = 0 ; 
        int j =0 ; 
        
        
        while( j < n ){
            xorr ^= arr[j];
            if(j - i + 1 == k ){
                result = max(result , xorr);
                xorr ^= arr[i];
                i++;
            }
            j++;
            
        }
        return result;
        
    }
};
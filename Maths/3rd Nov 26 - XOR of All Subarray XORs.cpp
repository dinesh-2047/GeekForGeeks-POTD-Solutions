// XOR of All Subarray XORs

class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        int n = arr.size();
        
        int xorr = 0 ; 
        
        if(n %2 == 0) return 0 ; 
        
        for(int i = 0 ; i  < n ; i+=2){
            xorr ^= arr[i];
        }
        
      return xorr;              
        
    }
};
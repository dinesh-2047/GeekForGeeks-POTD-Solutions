// Game of XOR

class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        int n = arr.size();
        
        int xorr = 0 ; 
        
        for(int i = 0 ; i  < n; i++){
            int part = (i + 1) * (n - i);
            if(part %2 == 0){
                xorr ^= 0;
            }
            else xorr ^= arr[i];
        }
        return xorr; 
        
    }
};
// Count set bits


class Solution {
  public:
    int countSetBits(int n) {
        int result = 0 ; 
         while(n > 0 ){
             int x = log2(n); // largest power of 2 <= n ; 
             
            result += x * (1<<(x- 1)) + n - (1 << x) + 1; 
            n -= (1 << x);
         }
        
        return result; 
    }
};

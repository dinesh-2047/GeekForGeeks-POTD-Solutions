// Sum of All Digit Subsequences

class Solution {
  public:
    int subsequenceSum(string &s) {
       
        int n = s.length();
        int mod = 1e9 + 7 ; 
        long long sum = 0;
        for(auto &ch  : s){
            sum  = (sum + (ch - '0'))%mod; 
        }
        
        long long pow2 = 1; 
        for(int i = 0 ; i  < n -1 ; i++){
            pow2 = (pow2 * 2)%mod; 
        }
        return (sum * pow2)%mod; 
    }
};
// Balanced Binary Tree Counter

class Solution {
  public:
  int mod = 1e9 + 7 ; 
  using ll = long long ; 
    int countBT(int h) {
       ll a = 1; 
       ll b = 1; 
       ll c ; 
       for(int i = 2; i  <= h; i++){
            c = b * ((2 * a)+b)%mod; 
           a = b ; 
           b = c ; 
       }
       return c; 
       
        
    }
};
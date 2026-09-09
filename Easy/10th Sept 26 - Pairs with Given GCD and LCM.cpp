// Pairs with Given GCD and LCM

class Solution {
  public:
    int pairCount(int x, int y) {
        int prod = x  * y ; 
         int result = 0 ;
        for(int i = 1 ; i * i <= prod; i++){
            if(prod%i==0){
                int a = i ; 
                int b = prod/i; 
                
                if(gcd(a, b) == x && lcm(a, b) == y ){
                    result++;
                    if(a!=b) result++;
                }
            }
        }
        return result; 
        
    }
};
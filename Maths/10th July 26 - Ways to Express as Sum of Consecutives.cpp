// Ways to Express as Sum of Consecutives

class Solution {
  public:
    int getCount(int n) {
        int i = 1; 
        int j = 0 ; 
        
        int k = 0 ; 
        
        while(n > 0 ){
            n = n - i ; 
            if(n%i == 0 ) k++;
            i++;
        }
        return k - 1 ; 
        
    }
};
//
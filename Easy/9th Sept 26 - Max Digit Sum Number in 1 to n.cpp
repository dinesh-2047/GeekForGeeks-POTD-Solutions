// Max Digit Sum Number in 1 to n


class Solution {
  public:
  int digitSum(int x){
      int sum = 0 ; 
      while(x){
          sum += (x%10);
          x/=10; 
      }
      return sum; 
  }
    int findMax(int n) {
        int b = 1; 
        int result = n ;
        
        while(n){
            int curr = (n-1)*b + ( b- 1);
            
            if(digitSum(curr) > digitSum(result) || digitSum(curr) == digitSum(result) && curr > result){
                result = curr; 
            }
            
            b = b * 10; 
            n /= 10; 
            
             
        }
        return result;
        
    }
};

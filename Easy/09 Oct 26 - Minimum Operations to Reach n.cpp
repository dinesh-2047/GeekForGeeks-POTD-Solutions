// Minimum Operations to Reach n

class Solution {
  public:
    int minOperation(int n) {
        int result = 0;
       while(n > 0){
           if(n%2 == 0 ){
               n/=2; 
           }
           else n--;
           result++;
       }
       return result;
        
    }
};
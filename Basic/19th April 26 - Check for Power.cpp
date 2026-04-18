// Check for Power

class Solution {
  public:
    bool isPower(int x, int y) {
       for(int p = 0 ; p <= 31; p++){
           if(pow(x , p) == y){
               return true; 
           }
       }
       return false; 
        
    }
};
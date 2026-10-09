// Balancing with Distinct Powers

class Solution {
  public:
    bool balancePan(int a, int b) {
        while(b) {
            int r = b%a; 
            if(r == 0 || r == 1){
                b/=a;
            }
            else if(r == a- 1){
                b = b /a + 1; 
            }
            else return false; 
        }
        return true; 
    }
};
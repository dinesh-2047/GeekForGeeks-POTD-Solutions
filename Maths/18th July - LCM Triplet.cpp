// LCM Triplet


// Approach 1 : Simple logical calculation

class Solution {
  public:
  int gcd(int a , int b){
      if(b==0) return a; 
      
      return gcd(b, a%b);
  }
  
  int lcm(int a  ,int b){
      if(a==0 || b== 0) return 0 ; 
      
      return (a*b)/gcd(a, b);
  }
  
    int lcmTriplets(int n) {
        if(n < 3) return n; 
        int lcm_a_b_c = 0;
        if(n%2==1){
        int lcm_a_b =  lcm(n , n-1);
         lcm_a_b_c = lcm(lcm_a_b, n-2);
        
        return lcm_a_b_c;
        }
        else{
            if(gcd(n , n-3)==1){
                int lcm_a_b =  lcm(n , n-1);
         lcm_a_b_c = lcm(lcm_a_b, n-3);
            }
            else{
                int lcm_a_b =  lcm(n-1 , n-2);
         lcm_a_b_c = lcm(lcm_a_b, n-3);
            }
        }
        return  lcm_a_b_c;
        
    }
};












//Approach 2 :using smiple multiplication 
class Solution {
  public:
    int lcmTriplets(int n) {
        
        if(n < 3) return n; 
        int lcm = 0 ; 
        
        if(n%2==1){
            lcm = n* (n-1) * (n-2);
        }
      
            else if(n%3){
                lcm = n * (n-1) * (n-3);
            }
            else lcm = (n-1)*(n-2)*(n-3);
        
        
        return lcm ; 
        
    }
};
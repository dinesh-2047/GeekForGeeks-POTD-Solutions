// Divisible by 13


class Solution {
  public:
    bool divby13(string &s) {
      int n = s.length();
      
      int rem = 0 ; 
      
      for(int i = 0 ; i <n; i++){
          rem = (rem * 10 + s[i]-'0')%13;
    }
    
    return rem == 0 ; 
    }
};
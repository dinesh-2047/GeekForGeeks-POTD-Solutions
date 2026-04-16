// Implement Atoi


class Solution {
  public:
    int myAtoi(string &s) {
      int n = s.length();
      
      bool is_digit_present = false; 
      for(auto &ch : s){
          if(isdigit(ch)){
              is_digit_present = true; 
              break; 
          }
      }
      
      if(!is_digit_present) return 0; 
      
      
     long long result = 0; 
      char sign = '+';
      
      for(auto &ch : s){
          if(ch == '-'){
              sign = '-';
              break; 
          }
      }
      
      int i = 0 ; 
      while(i < n && (s[i] == ' ' || s[i] == '+' || s[i] == '-')) i++;
      
      
      
      while(i < n && isdigit(s[i])){
     
          result = (result * 10 ) + (s[i] - '0');
         
          i++;
      }
  
      
      if(sign == '+'){
          if(result > INT_MAX) return INT_MAX; 
          else return result; 
      }
      
      if(sign == '-'){
          if(result > INT_MAX) return INT_MIN; 
          return (int) -1 * result; 
      }
      
      return result; 
        
    }
};

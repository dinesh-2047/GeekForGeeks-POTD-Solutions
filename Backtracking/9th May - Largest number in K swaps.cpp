// Largest number in K swaps


class Solution {
    public:
      void solve(string &s, string &ans, int idx, int k ){
          ans = max(ans, s);
          if(k==0) return; 
          
          for(int i = idx ; i < s.length()-1; i++){
              for(int j = i + 1; j  < s.length(); j++){
                  if(s[j] > s[i]){ 
              swap(s[i], s[j]);
                  k--;
                  
                  solve(s, ans , i, k );
                  
                  swap(s[i],s[j]);
                  k++;
              }
              }
          }
      }
      
      
      string findMaximumNum(string& s, int k) {
         int n = s.length();
        
         string ans = "";
         
         solve(s, ans , 0,k );
         return ans; 
      }
  };
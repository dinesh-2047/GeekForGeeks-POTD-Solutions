// Substring with Max Zero-One Diff


class Solution {
  public:
    int maxSubstring(string &s) {
        int n = s.length();
        
        int count0 = 0; 
        int count1 = 0 ; 
        
        int result  = -1; 
        
        for(auto &ch : s){
            if(ch == '0') count0++;
           else  count1++;
            
            int total = count0 - count1; 
            
            result = max(total , result);
            
            if(total < 0 ){
                count0 = 0 ; 
                count1 = 0 ; 
            }
        }
        return result; 
    }
};
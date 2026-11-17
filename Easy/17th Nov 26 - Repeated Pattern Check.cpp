// Repeated Pattern Check


class Solution {
  public:
    bool findPattern(string& s) {
        int n = s.length();
        
        int count = 0 ; 
        
        for(int i = 0; i  < n; i++){
            if(s[i] == 'x'){
                count++;
            }
            else {
                 while(i < n && s[i] == 'y'){
                     count--;
                     i++;
                 }
                 if(count != 0 ) return false; 
                 i--;
            }
        }
        return count == 0 ; 
    }
};